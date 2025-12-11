/** \file display.cpp
 *  \brief Implementation file for C++ wrapper for LVGL display driver.
 *  This is a base class made to connect a screen driver with LVGL.
 *
 *  Author: Vincent Paeder
 *  License: MIT
 */
#include "display.h"
#include "object.h"
#include "theme.h"
#include "../draw/image.h"

namespace lvgl::core {

    Display::Display(lv_coord_t hor_res, lv_coord_t ver_res) 
    : hor_res(hor_res), ver_res(ver_res) {
        this->lv_obj = LvPointerType(lv_display_create(hor_res, ver_res));
    }

    void Display::flush_ready() {
        lv_display_flush_ready(this->raw_ptr());
    }

    void Display::set_default() {
        lv_display_set_default(this->raw_ptr());
    }

    bool Display::is_default() const {
        return lv_display_get_default() == this->raw_ptr();
    }

    lv_coord_t Display::get_hor_res() const {
        return lv_display_get_horizontal_resolution(const_cast<lv_display_t*>(this->raw_ptr()));
    }

    lv_coord_t Display::get_ver_res() const {
        return lv_display_get_vertical_resolution(const_cast<lv_display_t*>(this->raw_ptr()));
    }

    lv_coord_t Display::get_physical_hor_res() const {
        return lv_display_get_physical_horizontal_resolution(const_cast<lv_display_t*>(this->raw_ptr()));
    }

    lv_coord_t Display::get_physical_ver_res() const {
        return lv_display_get_physical_vertical_resolution(const_cast<lv_display_t*>(this->raw_ptr()));
    }

    lv_coord_t Display::get_offset_x() const {
        return lv_display_get_offset_x(const_cast<lv_display_t*>(this->raw_ptr()));
    }

    lv_coord_t Display::get_offset_y() const {
        return lv_display_get_offset_y(const_cast<lv_display_t*>(this->raw_ptr()));
    }

    bool Display::get_antialiasing() const {
        return lv_display_get_antialiasing(const_cast<lv_display_t*>(this->raw_ptr()));
    }

    lv_coord_t Display::get_dpi() const {
        return lv_display_get_dpi(this->raw_ptr());
    }

    void Display::set_rotation(lv_display_rotation_t rotation) {
        lv_display_set_rotation(this->raw_ptr(), rotation);
    }

    lv_display_rotation_t Display::get_rotation() const {
        return lv_display_get_rotation(const_cast<lv_display_t*>(this->raw_ptr()));
    }

    Object Display::get_scr_act() const {
        return Object(lv_display_get_screen_active(const_cast<lv_display_t*>(this->raw_ptr())), false);
    }

    Object Display::get_scr_prev() const {
        return Object(lv_display_get_screen_prev(const_cast<lv_display_t*>(this->raw_ptr())), false);
    }

    Object Display::get_layer_top() const {
        return Object(lv_display_get_layer_top(const_cast<lv_display_t*>(this->raw_ptr())), false);
    }

    Object Display::get_layer_sys() const {
        return Object(lv_display_get_layer_sys(const_cast<lv_display_t*>(this->raw_ptr())), false);
    }

    void Display::set_theme(Theme & th) {
        lv_display_set_theme(this->raw_ptr(), th.raw_ptr());
    }

    Theme Display::get_theme() const {
        return Theme(lv_display_get_theme(const_cast<lv_display_t*>(this->raw_ptr())), false);
    }

    void Display::enable_invalidation(bool en) {
        lv_display_enable_invalidation(this->raw_ptr(), en);
    }

    bool Display::is_invalidation_enabled() {
        return lv_display_is_invalidation_enabled(this->raw_ptr());
    }

    uint32_t Display::get_inactive_time() const {
        return lv_display_get_inactive_time(this->raw_ptr());
    }

    void Display::trigger_activity() {
        lv_display_trigger_activity(this->raw_ptr());
    }

    void screen_load(Object & scr) {
        lv_screen_load(scr.raw_ptr());
    }

    Object screen_active() {
        return Object(lv_screen_active(), false);
    }

    Object layer_top() {
        return Object(lv_layer_top(), false);
    }

    Object layer_sys() {
        return Object(lv_layer_sys(), false);
    }

}

