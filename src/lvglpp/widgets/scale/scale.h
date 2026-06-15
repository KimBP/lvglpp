/** \file button.h
 *  \brief Header file for C++ wrapper for lv_scale_t objects.
 *
 *  Author: Kim Bøndergaard
 *  License: MIT
 */
#pragma once

#include "../../core/object.h"
#include "widgets/scale/lv_scale_private.h"

#if LV_USE_SCALE != 0

namespace lvgl::widgets {

    using namespace lvgl::core;

    /** \class Scale
     *  \brief Wraps a lv_scale_t object.
     */
    class Scale : public Widget<lv_scale_create> {
    public:
        using Widget::Widget;

        using SectionHdl = lv_scale_section_t*;

        void set_mode(lv_scale_mode_t mode);
        void set_total_tick_count(uint32_t total_tick_count);
        void set_major_tick_every(uint32_t major_tick_every);
        void set_label_show(bool show_label);
        void set_range(int32_t min, int32_t max);
        void set_angle_range(uint32_t angle_range);
        void set_rotation(int32_t rotation);
        void set_line_needle_value(Object & needle_line, int32_t needle_length, int32_t value);
        void set_image_needle_value(Object & needle_img, int32_t value);
        void set_text_src(const char * txt_src[]);
        void set_post_draw(bool en);
        void set_draw_ticks_on_top(bool en);

        lv_scale_mode_t get_mode();
        int32_t get_total_tick_count();
        int32_t get_major_tick_every();
        int32_t get_rotation();
        bool get_label_show();
        uint32_t get_angle_range();
        int32_t get_range_min_value();
        int32_t get_range_max_value();

        SectionHdl add_section();
        void set_section_range(SectionHdl section, int32_t min, int32_t max);
        void set_section_style_main(SectionHdl section, const lv_style_t * style);
        void set_section_style_indicator(SectionHdl section, const lv_style_t * style);
        void set_section_style_items(SectionHdl section, const lv_style_t * style);
    };

}
#endif // LV_USE_SCALE
