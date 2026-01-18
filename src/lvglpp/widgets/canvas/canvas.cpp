/** \file canvas.cpp
 *  \brief Implementation file for C++ wrapper for lv_canvas_t objects.
 *
 *  Author: Vincent Paeder
 *  License: MIT
 */
#include "canvas.h"
#if LV_USE_CANVAS != 0

#include "../../misc/area.h"
#include "../../draw/desc.h"

namespace lvgl::widgets {

    void Canvas::set_px(lv_coord_t x, lv_coord_t y, lv_color_t c, lv_opa_t opa) {
        lv_canvas_set_px(this->raw_ptr(), x, y, c, opa);
    }

    void Canvas::set_buffer(DrawBuf & draw_buf) {
        lv_canvas_set_draw_buf(this->raw_ptr(), draw_buf.raw_ptr());
    }

    void Canvas::set_px_opa(lv_coord_t x, lv_coord_t y, lv_opa_t opa) {
        lv_color32_t col32 = get_px(x, y);
        lv_color_t col;
        col.blue = col32.blue;
        col.red = col32.red;
        col.green = col32.green;
        set_px(x,y, col, opa);
    }

    void Canvas::set_palette(uint8_t id, lv_color32_t c) {
        lv_canvas_set_palette(this->raw_ptr(), id, c);
    }

    lv_color32_t Canvas::get_px(lv_coord_t x, lv_coord_t y) const {
        return lv_canvas_get_px(const_cast<lv_cls_ptr>(this->raw_ptr()), x, y);
    }

    std::shared_ptr<lv_img_dsc_t> Canvas::get_img() const {
        return std::shared_ptr<lv_img_dsc_t>(
            lv_canvas_get_image(const_cast<lv_cls_ptr>(this->raw_ptr())));
    }

    void Canvas::copy_buf(const lv_area_t * src_area, lv_draw_buf_t * dest_buf, const lv_area_t * dest_area) {
        lv_canvas_copy_buf(this->raw_ptr(), src_area, dest_buf, dest_area);
    }

    void Canvas::copy_buf(const Area & src_area, lv_draw_buf_t & dest_buf, const Area & dest_area) {
        copy_buf(src_area.raw_ptr(), &dest_buf, dest_area.raw_ptr());
    }

    void Canvas::fill_bg(const lv_color_t & color, lv_opa_t opa) {
        lv_canvas_fill_bg(this->raw_ptr(), color, opa);
    }

    void Canvas::init_layer(Layer & layer) {
        lv_canvas_init_layer(this->raw_ptr(), layer.raw_ptr());
    }

    void Canvas::finish_layer(Layer & layer) {
        lv_canvas_finish_layer(this->raw_ptr(), layer.raw_ptr());
    }

}
#endif // LV_USE_CANVAS