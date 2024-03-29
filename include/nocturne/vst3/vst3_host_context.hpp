#ifndef NOCTURNE_VST3_HOST_CONTEXT_HPP
#define NOCTURNE_VST3_HOST_CONTEXT_HPP

#include <nocturne/vst3/vst3_headers.hpp>

namespace nocturne::vst3 {
    class HostContext
            : public Steinberg::FObject,
              public Steinberg::Vst::IHostApplication,
              public Steinberg::Vst::IComponentHandler,
              public Steinberg::Vst::IComponentHandler2,
              public Steinberg::Vst::IUnitHandler,
              public Steinberg::Vst::IUnitHandler2,
              public Steinberg::IPlugFrame,
              public Steinberg::Vst::IPlugInterfaceSupport {
    public:
        Steinberg::tresult queryInterface(const char *_iid, void **obj) override;

        Steinberg::uint32 addRef() override;

        Steinberg::uint32 release() override;

        Steinberg::tresult resizeView(Steinberg::IPlugView *view, Steinberg::ViewRect *newSize) override;

        Steinberg::tresult beginEdit(Steinberg::Vst::ParamID id) override;

        Steinberg::tresult performEdit(Steinberg::Vst::ParamID id, Steinberg::Vst::ParamValue valueNormalized) override;

        Steinberg::tresult endEdit(Steinberg::Vst::ParamID id) override;

        Steinberg::tresult restartComponent(Steinberg::int32 flags) override;

        Steinberg::tresult setDirty(Steinberg::TBool state) override;

        Steinberg::tresult requestOpenEditor(Steinberg::FIDString name) override;

        Steinberg::tresult startGroupEdit() override;

        Steinberg::tresult finishGroupEdit() override;

        Steinberg::tresult getName(Steinberg::Vst::TChar *name) override;

        Steinberg::tresult createInstance(char *cid, char *_iid, void **obj) override;

        Steinberg::tresult isPlugInterfaceSupported(const char *_iid) override;

        Steinberg::tresult notifyUnitSelection(Steinberg::Vst::UnitID unitId) override;

        Steinberg::tresult
        notifyProgramListChange(Steinberg::Vst::ProgramListID listId, Steinberg::int32 programIndex) override;

        Steinberg::tresult notifyUnitByBusChange() override;
    };

}
#endif //NOCTURNE_VST3_HOST_CONTEXT_HPP
