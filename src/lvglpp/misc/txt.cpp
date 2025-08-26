/** \file timer.h
 *  \brief Header file for C++ wrapper for LVGL text functions.
 *
 *  Author: Kim Bøndergaard
 *  License: MIT
 */
#include "txt.h"

namespace lvgl::misc {

    namespace txt {

        lv_point_t get_size(const std::string & text, const lv_font_t * font,
                            lv_coord_t letter_space, lv_coord_t line_space,
                            lv_coord_t max_width, lv_text_flag_t flag) {
            lv_point_t size_res;
            lv_txt_get_size(&size_res, text.c_str(), font, letter_space, line_space, 
                            max_width, flag);
            return size_res;
        }

        lv_point_t get_size(const std::string & text, const font::Font & font,
                            lv_coord_t letter_space, lv_coord_t line_space,
                            lv_coord_t max_width, lv_text_flag_t flag) {
            return get_size(text, font.raw_ptr(), letter_space, line_space,
                            max_width, flag);
        }

        lv_coord_t get_width(const std::string & txt, const lv_font_t * font,
                             lv_coord_t letter_space, lv_text_flag_t flag) {
            return lv_txt_get_width(txt.c_str(), txt.size(), font, letter_space, flag);
        }

        lv_coord_t get_width(const std::string & txt, const font::Font & font,
                             lv_coord_t letter_space, lv_text_flag_t flag) {
            return get_width(txt, font.raw_ptr(), letter_space, flag);
        }

    }
}
