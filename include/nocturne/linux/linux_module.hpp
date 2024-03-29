#ifndef NOCTURNE_LINUX_MODULE_HPP
#define NOCTURNE_LINUX_MODULE_HPP

#include <nocturne/imodule.hpp>

#include <nocturne/vst3/vst3_headers.hpp>

#include <dlfcn.h>

namespace nocturne {
    class LinuxModule : public IModule {
    private:
        void *m_module{nullptr};
        VST3::Hosting::PluginFactory m_factory{nullptr};

    public:
        LinuxModule() = default;

        bool load(const std::string &path) override;

        void list_classes();

        template<typename T>
        T getFunction(char const *name) {
            return reinterpret_cast<T>(dlsym(m_module, name));
        }

    };
}

#endif //NOCTURNE_LINUX_MODULE_HPP
