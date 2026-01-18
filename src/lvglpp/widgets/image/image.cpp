/** \file image.cpp
 *  \brief Implementation file for C++ wrapper for lv_image_t objects.
 *
 *  Author: Vincent Paeder
 *  License: MIT
 */
#include "image.h"

#if LV_USE_IMAGE != 0

#include "../../draw/image.h"

namespace lvgl::widgets {

    void Image::set_src(const ImageDescriptor & src) {
        lv_image_set_src(this->raw_ptr(), src.raw_ptr());
    }

    void Image::set_src(const std::string & src) {
        lv_image_set_src(this->raw_ptr(), src.c_str());
    }

    void Image::set_offset_x(lv_coord_t x) {
        lv_image_set_offset_x(this->raw_ptr(), x);
    }

    void Image::set_offset_y(lv_coord_t y) {
        lv_image_set_offset_y(this->raw_ptr(), y);
    }

    void Image::set_rotation(int32_t angle) {
        lv_image_set_rotation(this->raw_ptr(), angle);
    }

    void Image::set_pivot(lv_coord_t x, lv_coord_t y) {
        lv_image_set_pivot(this->raw_ptr(), x, y);
    }

    void Image::set_scale(uint32_t zoom) {
        lv_image_set_scale(this->raw_ptr(), zoom);
    }

    void Image::set_antialias(bool antialias) {
        lv_image_set_antialias(this->raw_ptr(), antialias);
    }

#ifdef MISSING_PORT
    void Image::set_size_mode(lv_img_size_mode_t mode) {
        lv_img_set_size_mode(this->raw_ptr(), mode);
    }
#endif

    lv_image_src_t Image::get_src_type() const {
        return lv_image_src_get_type(lv_image_get_src(const_cast<lv_obj_t*>(this->raw_ptr())));
    }

    const ImageDescriptor Image::get_src_img() const {
        assert(this->get_src_type() == LV_IMAGE_SRC_VARIABLE);
        return ImageDescriptor(
            const_cast<lv_image_dsc_t*>(reinterpret_cast<const lv_image_dsc_t*>(
                lv_image_get_src(const_cast<lv_obj_t*>(this->raw_ptr()))
            ))
        );
    }

    const std::string Image::get_src_str() const {
        auto src_type = this->get_src_type();
        assert(src_type == LV_IMAGE_SRC_FILE || src_type == LV_IMAGE_SRC_SYMBOL);
        return std::string(
            const_cast<char*>(reinterpret_cast<const char*>(
                lv_image_get_src(const_cast<lv_obj_t*>(this->raw_ptr()))
            ))
        );
    }

    lv_coord_t Image::get_offset_x() const {
        return lv_image_get_offset_x(const_cast<lv_obj_t*>(this->raw_ptr()));
    }

    lv_coord_t Image::get_offset_y() const {
        return lv_image_get_offset_y(const_cast<lv_obj_t*>(this->raw_ptr()));
    }

    int32_t Image::get_rotation() const {
        return lv_image_get_rotation(const_cast<lv_obj_t*>(this->raw_ptr()));
    }

    lv_point_t Image::get_pivot() const {
        lv_point_t pivot;
        lv_image_get_pivot(const_cast<lv_obj_t*>(this->raw_ptr()), &pivot);
        return pivot;
    }

    uint32_t Image::get_scale() const {
        return lv_image_get_scale(const_cast<lv_obj_t*>(this->raw_ptr()));
    }

    bool Image::get_antialias() const {
        return lv_image_get_antialias(const_cast<lv_obj_t*>(this->raw_ptr()));
    }

#ifdef MISSING_PORT
    lv_img_size_mode_t Image::get_size_mode() const {
        return lv_img_get_size_mode(const_cast<lv_obj_t*>(this->raw_ptr()));
    }
#endif

}
#endif // LV_USE_IMAGE
