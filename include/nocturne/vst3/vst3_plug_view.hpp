#ifndef NOCTURNE_VST3_PLUG_VIEW_HPP
#define NOCTURNE_VST3_PLUG_VIEW_HPP

#include <nocturne/vst3/vst3_headers.hpp>

#include <QWindow>

namespace nocturne::vst3 {
    class PlugView : public Steinberg::IPlugView {
    protected:
        QWindow *m_pluginWindow;

    public:
        Steinberg::uint32 addRef() override;

        Steinberg::uint32 release() override;

        Steinberg::tresult isPlatformTypeSupported(Steinberg::FIDString type) override;

        Steinberg::tresult attached(void *parent, Steinberg::FIDString type) override;

        Steinberg::tresult removed() override;

        Steinberg::tresult onWheel(float distance) override;

        Steinberg::tresult
        onKeyDown(Steinberg::char16 key, Steinberg::int16 keyCode, Steinberg::int16 modifiers) override;

        Steinberg::tresult
        onKeyUp(Steinberg::char16 key, Steinberg::int16 keyCode, Steinberg::int16 modifiers) override;

        Steinberg::tresult getSize(Steinberg::ViewRect *size) override;

        Steinberg::tresult onSize(Steinberg::ViewRect *newSize) override;

        Steinberg::tresult onFocus(Steinberg::TBool state) override;

        Steinberg::tresult setFrame(Steinberg::IPlugFrame *frame) override;

        Steinberg::tresult canResize() override;

        Steinberg::tresult checkSizeConstraint(Steinberg::ViewRect *rect) override;

        Steinberg::tresult PLUGIN_API queryInterface(const Steinberg::TUID _iid, void **obj) override {
            return Steinberg::kNotImplemented;
        }
    };
}

#endif //NOCTURNE_VST3_PLUG_VIEW_HPP
