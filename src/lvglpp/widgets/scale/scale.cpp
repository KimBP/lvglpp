/** \file scale.cpp
 *  \brief Implementation file for C++ wrapper for lv_scale_t objects.
 *
 *  Author: Kim Bøndergaard
 *  License: MIT
 */
#include "scale.h"
#if LV_USE_SCALE != 0

namespace lvgl::widgets {

        void Scale::set_mode(lv_scale_mode_t mode) {
            lv_scale_set_mode(this->raw_ptr(), mode);
        }

        void Scale::set_total_tick_count(uint32_t total_tick_count) {
            lv_scale_set_total_tick_count(this->raw_ptr(), total_tick_count);
        }

        void Scale::set_major_tick_every(uint32_t major_tick_every) {
            lv_scale_set_major_tick_every(this->raw_ptr(), major_tick_every);
        }

        void Scale::set_label_show(bool show_label) {
            lv_scale_set_label_show(this->raw_ptr(), show_label);
        }

        void Scale::set_range(int32_t min, int32_t max)  {
            lv_scale_set_range(this->raw_ptr(), min, max);
        }

        void Scale::set_angle_range(uint32_t angle_range) {
            lv_scale_set_angle_range(this->raw_ptr(), angle_range);
        }

        void Scale::set_rotation(int32_t rotation) {
            lv_scale_set_rotation(this->raw_ptr(), rotation);
        }

        void Scale::set_line_needle_value(Object & needle_line, int32_t needle_length, int32_t value) {
            lv_scale_set_line_needle_value(this->raw_ptr(), needle_line.raw_ptr(), needle_length, value);
        }

        void Scale::set_image_needle_value(Object & needle_img, int32_t value) {
            lv_scale_set_image_needle_value(this->raw_ptr(), needle_img.raw_ptr(), value);
        }
        void Scale::set_text_src(const char * txt_src[]) {
            lv_scale_set_text_src(this->raw_ptr(), txt_src);
        }

        void Scale::set_post_draw(bool en) {
            lv_scale_set_post_draw(this->raw_ptr(), en);
        }

        void Scale::set_draw_ticks_on_top(bool en) {
            lv_scale_set_draw_ticks_on_top(this->raw_ptr(), en);
        }

        lv_scale_mode_t Scale::get_mode() {
            return lv_scale_get_mode(this->raw_ptr());
        }

        int32_t Scale::get_total_tick_count() {
            return lv_scale_get_total_tick_count(this->raw_ptr());
        }
        
        int32_t Scale::get_major_tick_every() {
            return lv_scale_get_major_tick_every(this->raw_ptr());
        }
        
        int32_t Scale::get_rotation() {
            return lv_scale_get_rotation(this->raw_ptr());
        }
        
        bool Scale::get_label_show() {
            return lv_scale_get_label_show(this->raw_ptr());
        }
        
        uint32_t Scale::get_angle_range() {
            return lv_scale_get_angle_range(this->raw_ptr());
        }
        
        int32_t Scale::get_range_min_value() {
            return lv_scale_get_range_min_value(this->raw_ptr());
        }
        
        int32_t Scale::get_range_max_value() {
            return lv_scale_get_range_max_value(this->raw_ptr());
        }
        
 
        Scale::SectionHdl Scale::add_section() {
            return lv_scale_add_section(this->raw_ptr());
        }

        void Scale::set_section_range(SectionHdl section, int32_t min, int32_t max) {
            lv_scale_set_section_range(this->raw_ptr(), section, min, max);
        }

        void Scale::set_section_style_main(SectionHdl section, const lv_style_t * style) {
            lv_scale_set_section_style_main(this->raw_ptr(), section, style);
        }

        void Scale::set_section_style_indicator(SectionHdl section, const lv_style_t * style) {
            lv_scale_set_section_style_indicator(this->raw_ptr(), section, style);
        }
        void Scale::set_section_style_items(SectionHdl section, const lv_style_t * style) {
            lv_scale_set_section_style_items(this->raw_ptr(), section, style);
        }

}
#endif // LV_USE_SCALE
