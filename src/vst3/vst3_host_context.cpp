#include <nocturne/vst3/vst3_host_context.hpp>

#include <plog/Log.h>

namespace nocturne::vst3 {
    HostContext::HostContext(std::string &&host_name) : m_host_name{std::move(host_name)} {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;

    }

    HostContext::~HostContext() {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;

    }

    Steinberg::tresult HostContext::resizeView(Steinberg::IPlugView *view, Steinberg::ViewRect *newSize) {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

    Steinberg::tresult HostContext::beginEdit(Steinberg::Vst::ParamID id) {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

    Steinberg::tresult
    HostContext::performEdit(Steinberg::Vst::ParamID id, Steinberg::Vst::ParamValue valueNormalized) {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

    Steinberg::tresult HostContext::endEdit(Steinberg::Vst::ParamID id) {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

    Steinberg::tresult HostContext::restartComponent(Steinberg::int32 flags) {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

    Steinberg::tresult HostContext::setDirty(Steinberg::TBool state) {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

    Steinberg::tresult HostContext::requestOpenEditor(Steinberg::FIDString name) {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

    Steinberg::tresult HostContext::startGroupEdit() {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

    Steinberg::tresult HostContext::finishGroupEdit() {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

    Steinberg::tresult HostContext::getName(Steinberg::Vst::TChar *name) {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

    Steinberg::tresult HostContext::createInstance(char *cid, char *_iid, void **obj) {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

    Steinberg::tresult HostContext::isPlugInterfaceSupported(const char *_iid) {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

    Steinberg::tresult HostContext::notifyUnitSelection(Steinberg::Vst::UnitID unitId) {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

    Steinberg::tresult
    HostContext::notifyProgramListChange(Steinberg::Vst::ProgramListID listId, Steinberg::int32 programIndex) {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

    Steinberg::tresult HostContext::notifyUnitByBusChange() {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

}
