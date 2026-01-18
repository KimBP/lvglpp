/** \file draw_buf.cpp
 *  \brief Header file for C++ wrapper for LVGL draw descriptors.
 *
 *  Author: Kim Bøndergaard
 *  License: MIT
 */
#include "draw_buf.h"
#include "../core/object.h"

/** \namespace lvgl::draw
 *  \brief LVGL draw components.
 */
namespace lvgl::draw {
    
    using namespace lvgl::core;

    DrawBuf::DrawBuf(uint32_t w, uint32_t h, lv_color_format_t cf, uint32_t stride,
                     std::vector<uint8_t> & data) {
        this->lv_obj = LvPointerType(lv_cls_alloc<lv_cls>());
        lv_draw_buf_init(this->raw_ptr(), w, h, cf, stride, data.data(), data.size());
    }

    DrawBuf::DrawBuf(lv_draw_buf_t * lv_draw_buf) {
        this->owns_ptr = false;
        this->lv_obj = LvPointer<lv_draw_buf_t, lv_free>(lv_draw_buf);
    }

    DrawBuf::DrawBuf(const DrawBuf & other) {
        // Doesn't handle nullptr being returned from lv_draw_buf_dup()
        this->owns_ptr = false;
        this->lv_obj = LvPointer<lv_draw_buf_t, lv_free>(lv_draw_buf_dup(other.raw_ptr()));
    }

    DrawBuf DrawBuf::create(uint32_t w, uint32_t h, lv_color_format_t cf, uint32_t stride) {
        // Doesn't handle nullptr being returned from lv_draw_buf_create()
        return DrawBuf(lv_draw_buf_create(w, h, cf, stride));
    }

    uint32_t DrawBuf::width_to_stride(uint32_t w, lv_color_format_t cf) {
        return lv_draw_buf_width_to_stride(w, cf);
    }

    void DrawBuf::reshape(uint32_t w, uint32_t h, lv_color_format_t cf, uint32_t stride) {
        // Doesn't handle if new size can' be contained in allocated buffer
        (void)lv_draw_buf_reshape(this->raw_ptr(), cf, w, h, stride);
    }

    void * DrawBuf::goto_xy(uint32_t x, uint32_t y) {
        return lv_draw_buf_goto_xy(this->raw_ptr(), x, y);
    }

    lv_result_t DrawBuf::adjust_stride(uint32_t stride) {
        return lv_draw_buf_adjust_stride(this->raw_ptr(), stride);
    }

    lv_result_t DrawBuf::premultiply() {
        return lv_draw_buf_premultiply(this->raw_ptr());
    }

    void DrawBuf::set_palette(uint8_t index, lv_color32_t color) {
        lv_draw_buf_set_palette(this->raw_ptr(), index, color);
    }

    bool DrawBuf::has_flag(lv_image_flags_t flag) const {
        return lv_draw_buf_has_flag(this->raw_ptr(), flag);
    }

    void DrawBuf::set_flag(lv_image_flags_t flag) {
        lv_draw_buf_set_flag(this->raw_ptr(), flag);
    }

    void DrawBuf::clear_flag(lv_image_flags_t flag) {
        lv_draw_buf_clear_flag(this->raw_ptr(), flag);
    }

    lv_result_t DrawBuf::from_image(const ImageDescriptor & img) {
        return lv_draw_buf_from_image(this->raw_ptr(), img.raw_ptr());
    }

    void DrawBuf::to_image(ImageDescriptor & img) {
        lv_draw_buf_to_image(this->raw_ptr(), img.raw_ptr());
    }

    Area DrawBuf::get_area() const {
        auto raw = this->raw_ptr();
        return Area(0, 0, raw->header.w, raw->header.h);
    }
}
