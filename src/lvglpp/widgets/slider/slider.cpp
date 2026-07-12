/** \file slider.cpp
 *  \brief Implementation file for C++ wrapper for lv_slider_t objects.
 *
 *  Author: Vincent Paeder
 *  License: MIT
 */
#include "slider.h"
#if LV_USE_SLIDER != 0

#include "../../core/group.h"

namespace lvgl::widgets {

namespace {

core::Group & fallback_slider_group()
{
    // lvglpp currently has no dedicated group factory helper.
    static core::Group group(lv_group_create(), false);
    return group;
}

void ensure_slider_group(Slider & slider)
{
    if (slider.get_group().raw_ptr() == nullptr) {
        fallback_slider_group().add_obj(slider);
    }
}

}

    Slider::Slider() : Widget() {
        ensure_slider_group(*this);
    }

    Slider::Slider(Object & parent) : Widget(parent) {
        ensure_slider_group(*this);
    }

    Slider::Slider(const Object & parent) : Widget(parent) {
        ensure_slider_group(*this);
    }

    void Slider::set_value(int32_t value, lv_anim_enable_t anim) {
        lv_slider_set_value(this->raw_ptr(), value, anim);
    }

    void Slider::set_left_value(int32_t value, lv_anim_enable_t anim) {
        lv_slider_set_left_value(this->raw_ptr(), value, anim);
    }

    void Slider::set_range(int32_t min, int32_t max) {
        lv_slider_set_range(this->raw_ptr(), min, max);
    }

    void Slider::set_mode(lv_slider_mode_t mode) {
        lv_slider_set_mode(this->raw_ptr(), mode);
    }

    int32_t Slider::get_value() const {
        return lv_slider_get_value(this->raw_ptr());
    }

    int32_t Slider::get_left_value() const {
        return lv_slider_get_left_value(this->raw_ptr());
    }

    int32_t Slider::get_min_value() const {
        return lv_slider_get_min_value(this->raw_ptr());
    }

    int32_t Slider::get_max_value() const {
        return lv_slider_get_max_value(this->raw_ptr());
    }

    bool Slider::is_dragged() const {
        return lv_slider_is_dragged(this->raw_ptr());
    }

    lv_slider_mode_t Slider::get_mode() const {
        return lv_slider_get_mode(const_cast<lv_cls_ptr>(this->raw_ptr()));
    }

}
#endif // LV_USE_SLIDER
