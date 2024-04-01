#include <nocturne/vst3/vst3_plug_view.hpp>

#include <plog/Log.h>

namespace nocturne::vst3 {
    Steinberg::tresult PlugView::isPlatformTypeSupported(Steinberg::FIDString type) {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

    Steinberg::tresult PlugView::attached(void *parent, Steinberg::FIDString type) {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

    Steinberg::tresult PlugView::removed() {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

    Steinberg::tresult PlugView::onWheel(float distance) {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

    Steinberg::tresult
    PlugView::onKeyDown(Steinberg::char16 key, Steinberg::int16 keyCode, Steinberg::int16 modifiers) {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

    Steinberg::tresult PlugView::onKeyUp(Steinberg::char16 key, Steinberg::int16 keyCode, Steinberg::int16 modifiers) {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

    Steinberg::tresult PlugView::getSize(Steinberg::ViewRect *size) {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

    Steinberg::tresult PlugView::onSize(Steinberg::ViewRect *newSize) {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

    Steinberg::tresult PlugView::onFocus(Steinberg::TBool state) {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

    Steinberg::tresult PlugView::setFrame(Steinberg::IPlugFrame *frame) {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

    Steinberg::tresult PlugView::canResize() {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

    Steinberg::tresult PlugView::checkSizeConstraint(Steinberg::ViewRect *rect) {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

    Steinberg::uint32 PlugView::addRef() {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

    Steinberg::uint32 PlugView::release() {
        PLOG(plog::debug) << __PRETTY_FUNCTION__;
        return 0;
    }

}
