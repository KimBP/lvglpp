/** \file image.h
 *  \brief Header file for C++ wrapper for lv_img_t objects.
 *
 *  Author: Vincent Paeder
 *  License: MIT
 */
#pragma once

#include "../../core/object.h"

#if LV_USE_IMAGE != 0

namespace lvgl::widgets {

    using namespace lvgl::core;
    
    /** \class Image
     *  \brief Wraps a lv_img_t object.
     */
    class Image : public Widget<lv_image_create> {
    public:
        using Widget::Widget;

        /** \fn void set_src(const ImageDescriptor & src)
         *  \brief Sets image source from image descriptor.
         *  \param src: image descriptor.
         */
        void set_src(const ImageDescriptor & src);

        /** \fn void set_src(const std::string & src)
         *  \brief Sets image source from string (file path or symbol name).
         *  \param src: source string.
         */
        void set_src(const std::string & src);

        /** \fn void set_offset_x(lv_coord_t x)
         *  \brief Sets image offset in x direction.
         *  \param x: offset in x direction.
         */
        void set_offset_x(lv_coord_t x);

        /** \fn void set_offset_y(lv_coord_t y)
         *  \brief Sets image offset in y direction.
         *  \param y: offset in y direction.
         */
        void set_offset_y(lv_coord_t y);

        /** \fn void set_angle(int16_t angle)
         *  \brief Sets image rotation angle.
         *  \param angle: rotation angle.
         * 
         *  Deprecated - use set_rotation()
         */
        void set_angle(int32_t angle) { set_rotation(angle); }

        /** \fn void set_rotation(int16_t angle)
         *  \brief Sets image rotation angle.
         *  \param angle: rotation angle.
         */
        void set_rotation(int32_t angle);

        /** \fn void set_pivot(lv_coord_t x, lv_coord_t y)
         *  \brief Sets rotation centre point.
         *  \param x: rotation centre x coordinate.
         *  \param y: rotation centre y coordinate.
         */
        void set_pivot(lv_coord_t x, lv_coord_t y);

        /** \fn void set_zoom(uint32_t zoom)
         *  \brief Sets image zoom factor.
         *  \param zoom: zoom factor.
         * 
         *  Deprecated - use set_scale()
         */
        void set_zoom(uint32_t zoom) { set_scale(zoom); }

        /** \fn void set_scale(uint32_t zoom)
         *  \brief Sets image zoom factor.
         *  \param zoom: zoom factor.
         */
        void set_scale(uint32_t zoom);

        /** \fn void set_antialias(bool antialias)
         *  \brief Turns antialiasing on or off.
         *  \param antialias: sets antialiasing on (true) or off (false).
         */
        void set_antialias(bool antialias);

#ifdef MISSING_PORT
        /** \fn void set_size_mode(lv_img_size_mode_t mode)
         *  \brief Sets image size mode. This affects the way out-of-bound pixels are treated.
         *  \param mode: size mode.
         */
        void set_size_mode(lv_img_size_mode_t mode);
#endif

        /** \fn lv_img_src_t get_src_type() const
         *  \brief Gets source type.
         *  \returns code for source type.
         */
        lv_image_src_t get_src_type() const;

        /** \fn const ImageDescriptor Image::get_src_img() const
         *  \brief Gets the image source descriptor.
         *  \returns the image source descriptor.
         */
        const ImageDescriptor get_src_img() const;

        /** \fn const std::string Image::get_src_str() const
         *  \brief Gets the image source path or symbol string.
         *  \returns the image source path or symbol string.
         */
        const std::string get_src_str() const;

        /** \fn lv_coord_t get_offset_x() const
         *  \brief Gets the image offset in x direction.
         *  \returns the image offset in x direction.
         */
        lv_coord_t get_offset_x() const;

        /** \fn lv_coord_t get_offset_y() const
         *  \brief Gets the image offset in y direction.
         *  \returns the image offset in y direction.
         */
        lv_coord_t get_offset_y() const;

        /** \fn uint16_t get_angle() const
         *  \brief Gets the image rotation angle.
         *  \returns the image rotation angle.
         *
         * Deprecated - use get_rotation()
         */
        int32_t get_angle() const { return get_rotation(); }

        /** \fn int32_t get_rotation() const
         *  \brief Gets the image rotation angle.
         *  \returns the image rotation angle.
         */
        int32_t get_rotation() const;

        /** \fn lv_point_t get_pivot() const
         *  \brief Gets the rotation centre point.
         *  \returns the rotation centre point.
         */
        lv_point_t get_pivot() const;

        /** \fn uint32_t get_zoom() const
         *  \brief Gets the zoom factor.
         *  \returns the zoom factor.
         * 
         *  Deprecated - use get_scale()
         */
        uint32_t get_zoom() const { return get_scale(); }

        /** \fn uint32_t get_scale() const
         *  \brief Gets the zoom factor.
         *  \returns the zoom factor.
         */
        uint32_t get_scale() const;

        /** \fn bool get_antialias() const
         *  \brief Gets whether antialiasing is enabled.
         *  \returns true if antialiasing is enabled, false otherwise.
         */
        bool get_antialias() const;

#ifdef MISSING_PORT
        /** \fn lv_img_size_mode_t get_size_mode() const
         *  \brief Gets image size mode.
         *  \returns the code for image size mode.
         */
        lv_img_size_mode_t get_size_mode() const;
#endif

    };

}
#endif // LV_USE_IMAGE
