#include <nocturne/imodule.hpp>
#include <nocturne/iplatform.hpp>
#include <nocturne/linux/linux_module.hpp>
#include <nocturne/vst3/vst3_headers.hpp>
#include <nocturne/vst3/vst3_plug_view.hpp>

#include <filesystem>
#include <optional>
#include <iostream>

#include <dlfcn.h>

#include <plog/Log.h>

#include <QWidget>

namespace nocturne {
    typedef Steinberg::IPluginFactory *(PLUGIN_API *GetFactoryProc)();

    extern "C" {
    using ModuleEntryFunc = bool (PLUGIN_API *)(void *);
    using ModuleExitFunc = bool (PLUGIN_API *)();
    }

    static std::optional<std::filesystem::path> getSOPath(const std::string &inPath) {
        std::filesystem::path modulePath{inPath};
        if (!std::filesystem::is_directory(modulePath))
            return {};

        auto stem = modulePath.stem();

        modulePath /= "Contents";
        if (!std::filesystem::is_directory(modulePath))
            return {};

        // use the Machine Hardware Name (from uname cmd-line) as prefix for "-linux"
        auto machine = g_platform->get_machine_name();
        if (!machine)
            return {};

        PLOG(plog::debug) << "machine: " << *machine;
        modulePath /= *machine + "-linux";
        if (!std::filesystem::is_directory(modulePath))
            return {};

        stem.replace_extension(".so");
        modulePath /= stem;

        return {std::move(modulePath)};
    }

    bool LinuxModule::load(const std::string &path, WId parent) {
        auto module_path = getSOPath(path);
        if (!module_path) {
            PLOG(plog::error) << "unable to find module: " << *module_path;

            return false;
        }

        m_module = dlopen(module_path->generic_string().data(), RTLD_LAZY);
        if (!m_module) {
            PLOG(plog::error) << "unable to dlopen module: " << *module_path;

            return false;
        }

        auto module_entry = getFunction<ModuleEntryFunc>("ModuleEntry");
        if (!module_entry) {
            PLOG(plog::error) << "unable to find module entry: " << *module_path;

            return false;
        }

        auto module_exit = getFunction<ModuleExitFunc>("ModuleExit");
        if (!module_exit) {
            PLOG(plog::error) << "unable to find module exit: " << *module_path;

            return false;
        }

        auto factory_proc = getFunction<GetFactoryProc>("GetPluginFactory");
        if (!factory_proc) {
            PLOG(plog::error) << "unable to find module entry: " << *module_path;

            return false;
        }

        if (!module_entry(m_module)) {
            PLOG(plog::error) << "error occured while calling module entry function: " << *module_path;

            return false;
        }

        auto f = Steinberg::FUnknownPtr<Steinberg::IPluginFactory>(Steinberg::owned(factory_proc()));

        m_factory = VST3::Hosting::PluginFactory{f};
        m_context = std::make_unique<vst3::HostContext>("nocturne");
        m_factory.setHostContext(m_context->unknownCast());
        Steinberg::PClassInfo class_info;
        m_factory.get()->getClassInfo(0, &class_info);
        Steinberg::FUnknown *instance{nullptr};
        m_plug_view = std::make_unique<vst3::PlugView>();
        Steinberg::tresult result = m_factory.get()->createInstance(class_info.cid, Steinberg::FUnknown::iid,
                                                                    reinterpret_cast<void **>(&instance));
        if (result != Steinberg::kResultOk) {
            PLOG(plog::fatal) << "unable to create instance: " << class_info.name;

            return false;
        }

        result = m_plug_view->attached((void *) parent, Steinberg::kPlatformTypeX11EmbedWindowID);
        if (result != Steinberg::kResultOk) {
            PLOG(plog::fatal) << "unable to attach view: " << class_info.name;

            return false;
        }

        return true;

    }

    void LinuxModule::list_classes() {
        for (uint32_t i = 0; i < m_factory.classCount(); ++i) {
            Steinberg::PClassInfo class_info;
            m_factory.get()->getClassInfo(i, &class_info);

            std::cout << class_info.name << ":" << class_info.category << std::endl;
        }
    }

}
