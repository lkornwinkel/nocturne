#include <nocturne/vst3/vst3_host_context.hpp>

namespace nocturne::vst3 {
    Steinberg::tresult HostContext::queryInterface(const char *_iid, void **obj) {
        return 0;
    }

    Steinberg::uint32 HostContext::addRef() {
        return 0;
    }

    Steinberg::uint32 HostContext::release() {
        return 0;
    }

    Steinberg::tresult HostContext::resizeView(Steinberg::IPlugView *view, Steinberg::ViewRect *newSize) {
        return 0;
    }

    Steinberg::tresult HostContext::beginEdit(Steinberg::Vst::ParamID id) {
        return 0;
    }

    Steinberg::tresult
    HostContext::performEdit(Steinberg::Vst::ParamID id, Steinberg::Vst::ParamValue valueNormalized) {
        return 0;
    }

    Steinberg::tresult HostContext::endEdit(Steinberg::Vst::ParamID id) {
        return 0;
    }

    Steinberg::tresult HostContext::restartComponent(Steinberg::int32 flags) {
        return 0;
    }

    Steinberg::tresult HostContext::setDirty(Steinberg::TBool state) {
        return 0;
    }

    Steinberg::tresult HostContext::requestOpenEditor(Steinberg::FIDString name) {
        return 0;
    }

    Steinberg::tresult HostContext::startGroupEdit() {
        return 0;
    }

    Steinberg::tresult HostContext::finishGroupEdit() {
        return 0;
    }

    Steinberg::tresult HostContext::getName(Steinberg::Vst::TChar *name) {
        return 0;
    }

    Steinberg::tresult HostContext::createInstance(char *cid, char *_iid, void **obj) {
        return 0;
    }

    Steinberg::tresult HostContext::isPlugInterfaceSupported(const char *_iid) {
        return 0;
    }

    Steinberg::tresult HostContext::notifyUnitSelection(Steinberg::Vst::UnitID unitId) {
        return 0;
    }

    Steinberg::tresult
    HostContext::notifyProgramListChange(Steinberg::Vst::ProgramListID listId, Steinberg::int32 programIndex) {
        return 0;
    }

    Steinberg::tresult HostContext::notifyUnitByBusChange() {
        return 0;
    }

}
