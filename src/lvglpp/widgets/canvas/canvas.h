/** \file canvas.h
 *  \brief Header file for C++ wrapper for lv_canvas_t objects.
 *
 *  Author: Vincent Paeder
 *  License: MIT
 */
#pragma once

#include "../../core/object.h"
#include "../../draw/image.h"
#include "../../draw/layer.h"
#include "../../draw/draw_buf.h"

#if LV_USE_CANVAS != 0

namespace lvgl::widgets {

    using namespace lvgl::core;
    
    /** \class Canvas
     *  \brief Wraps a lv_canvas_t object.
     */
    class Canvas : public Widget<lv_canvas_create> {
    public:
        using Widget::Widget;

        /** \fn template <class T> void set_buffer<T>(std::vector<T> & buf, lv_coord_t w, lv_coord_t h, lv_img_cf_t cf)
         *  \brief Sets buffer in which canvas data will be stored.
         *  \tparam T: buffer content type.
         *  \param buf: buffer.
         *  \param w: canvas width.
         *  \param h: canvas height.
         *  \param cf: color format.
         */
        template <class T> void set_buffer(std::vector<T> & buf, lv_coord_t w, lv_coord_t h, lv_color_format_t cf) {
            lv_canvas_set_buffer(this->raw_ptr(), buf.data(), w, h, cf);
        }

        /** \fn void set_buffer(DrawBuf & draw_buf)
         *  \brief Associates DrawBuf object to canvas
         *  \param draw_buf: The DrawBuf object to associate
         */
        void set_buffer(DrawBuf & draw_buf);

        /** \fn void set_buffer(ImageDescriptor & dsc)
         *  \brief Sets buffer in which canvas data will be stored.
         *  \param dsc: image descriptor serving as buffer.
         */
        void set_buffer(ImageDescriptor & dsc) {
            lv_canvas_set_buffer(this->raw_ptr(), const_cast<void*>(static_cast<const void*>(dsc->data)), dsc->header.w, dsc->header.h, static_cast<lv_color_format_t>(dsc->header.cf));
        }

        /** \fn void set_px(lv_coord_t x, lv_coord_t y, lv_color_t c, lv_opa_t opa)
         *  \brief Sets pixel color.
         *  \param x: pixel x coordinate.
         *  \param y: pixel y coordinate.
         *  \param c: color.
         *  \param opa: pixel opacity (0=transparent, 255=opaque).
         */
        void set_px(lv_coord_t x, lv_coord_t y, lv_color_t c, lv_opa_t opa);

        /** \fn void set_px_opa(lv_coord_t x, lv_coord_t y, lv_opa_t opa)
         *  \brief Sets pixel opacity.
         *  \param x: pixel x coordinate.
         *  \param y: pixel y coordinate.
         *  \param opa: pixel opacity (0=transparent, 255=opaque).
         *
         *  Deprecated - use set_px
         */
        void set_px_opa(lv_coord_t x, lv_coord_t y, lv_opa_t opa);

        /** \fn void set_palette(uint8_t id, lv_color_t c)
         *  \brief Sets palette color (if color format is indexed).
         *  \param id: color index.
         *  \param c: color.
         */
        void set_palette(uint8_t id, lv_color32_t c);

        /** \fn lv_color32_t get_px(lv_coord_t x, lv_coord_t y) const
         *  \brief Gets pixel color.
         *  \param x: pixel x coordinate.
         *  \param y: pixel y coordinate.
         *  \returns pixel color.
         */
        lv_color32_t get_px(lv_coord_t x, lv_coord_t y) const;

        /** \fn std::shared_ptr<lv_img_dsc_t> get_img() const
         *  \brief Gets canvas content as an image descriptor.
         *  \returns pointer to the image descriptor representing canvas content.
         */
        std::shared_ptr<lv_img_dsc_t> get_img() const;

        /** \fn void copy_buf(const lv_area_t * src_area, lv_draw_buf_t * dest_buf, const lv_area_t * dest_area)
         *  \brief Copies an area of the canvas buffer.
         *  \param src_area: buffer to copy from
         *  \param dest_buf: buffer to copy to
         *  \param dest_area: coordinates of area
         */
        void copy_buf(const lv_area_t * src_area, lv_draw_buf_t * dest_buf, const lv_area_t * dest_area);

        /** \fn void copy_buf(const Area & src_area, lv_draw_buf_t * dest_buf, const lv_area_t * dest_area)
         *  \brief Copies an area of the canvas buffer.
         *  \param src_area: buffer to copy from
         *  \param dest_buf: buffer to copy to
         *  \param dest_area: coordinates of area
         */
        void copy_buf(const Area & src_area, lv_draw_buf_t & dest_buf, const Area & dest_area);

        /** \fn void fill_bg(const lv_color_t & color, lv_opa_t opa)
         *  \brief Fill canvas with given color.
         *  \param color: color.
         *  \param opa: opacity.
         */
        void fill_bg(const lv_color_t & color, lv_opa_t opa);

        /** \fn void init_layer(Layer & layer)
         *  \brief Configures empty layer object
         *  \param layer: The layer being initiated
         */
        void init_layer(Layer & layer);

        /** \fn void finish_layer(Layer & layer)
         *  \brief Finishes what was initiated with init_layer()
         *  \param layer: Layer to finish
         */
        void finish_layer(Layer & layer);

    };

}
#endif // LV_USE_CANVAS