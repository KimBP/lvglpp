/** \file spinner.cpp
 *  \brief Implementation file for C++ wrapper for lv_spinner_t objects.
 *
 *  Author: Vincent Paeder
 *  License: MIT
 */
#include "spinner.h"
#if LV_USE_SPINNER

namespace lvgl::widgets {

    Spinner::Spinner() {
        this->lv_obj = LvPointer<lv_obj_t, lv_obj_del>(lv_spinner_create(nullptr));
    }

    Spinner::Spinner(Object & parent) {
        this->lv_obj = LvPointer<lv_obj_t, lv_obj_del>(lv_spinner_create(parent.raw_ptr()));
    }

    Spinner::Spinner(uint32_t time, uint32_t arc_length) {
        this->lv_obj = LvPointer<lv_obj_t, lv_obj_del>(lv_spinner_create(nullptr));
        set_anim_params(time, arc_length);
    }

    Spinner::Spinner(Object & parent, uint32_t time, uint32_t arc_length) {
        this->lv_obj = LvPointer<lv_obj_t, lv_obj_del>(lv_spinner_create(parent.raw_ptr()));
        set_anim_params(time, arc_length);
    }

    void Spinner::set_anim_params(uint32_t time, uint32_t arc_length)
    {
        lv_spinner_set_anim_params(this->raw_ptr(), time, arc_length);
    }
}
#endif // LV_USE_SPINNER