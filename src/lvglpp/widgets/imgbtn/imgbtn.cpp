/** \file imgbtn.cpp
 *  \brief Implementation file for C++ wrapper for lv_imagebutton_t objects.
 *
 *  Author: Vincent Paeder
 *  License: MIT
 */

 #include "src/widgets/imagebutton/lv_imagebutton_private.h"
 #include "imgbtn.h"
#if LV_USE_IMAGEBUTTON != 0

#include "../../draw/image.h"

namespace lvgl::widgets {

    void ImageButton::set_src_left_img(lv_imagebutton_state_t state, const ImageDescriptor & src) {
        lv_imagebutton_src_info_t* info = &reinterpret_cast<lv_imagebutton_t*>(this->raw_ptr())->src_left[state];

        (void)lv_image_decoder_get_info(src.raw_ptr(), &info->header);
        info->img_src = src.raw_ptr();
    }

    void ImageButton::set_src_left_str(lv_imagebutton_state_t state, const std::string & src) {
        lv_imagebutton_src_info_t* info = &reinterpret_cast<lv_imagebutton_t*>(this->raw_ptr())->src_left[state];
        (void)lv_image_decoder_get_info(src.c_str(), &info->header);
        info->img_src = src.c_str();
    }

    void ImageButton::set_src_mid_img(lv_imagebutton_state_t state, const ImageDescriptor & src) {
        lv_imagebutton_src_info_t* info = &reinterpret_cast<lv_imagebutton_t*>(this->raw_ptr())->src_mid[state];

        (void)lv_image_decoder_get_info(src.raw_ptr(), &info->header);
        info->img_src = src.raw_ptr();
    }

    void ImageButton::set_src_mid_str(lv_imagebutton_state_t state, const std::string & src) {
        lv_imagebutton_src_info_t* info = &reinterpret_cast<lv_imagebutton_t*>(this->raw_ptr())->src_mid[state];
        (void)lv_image_decoder_get_info(src.c_str(), &info->header);
        info->img_src = src.c_str();
    }

    void ImageButton::set_src_right_img(lv_imagebutton_state_t state, const ImageDescriptor & src) {
        lv_imagebutton_src_info_t* info = &reinterpret_cast<lv_imagebutton_t*>(this->raw_ptr())->src_right[state];

        (void)lv_image_decoder_get_info(src.raw_ptr(), &info->header);
        info->img_src = src.raw_ptr();
    }

    void ImageButton::set_src_right_str(lv_imagebutton_state_t state, const std::string & src) {
        lv_imagebutton_src_info_t* info = &reinterpret_cast<lv_imagebutton_t*>(this->raw_ptr())->src_right[state];
        (void)lv_image_decoder_get_info(src.c_str(), &info->header);
        info->img_src = src.c_str();
    }

    void ImageButton::set_state(lv_imagebutton_state_t state) {
        lv_imgbtn_set_state(this->raw_ptr(), state);
    }

    lv_image_src_t ImageButton::get_src_left_type(lv_imagebutton_state_t state) const {
        return lv_image_src_get_type(
            &reinterpret_cast<const lv_imagebutton_t*>(this->raw_ptr())->src_left[state]);
    }

    lv_image_src_t ImageButton::get_src_mid_type(lv_imagebutton_state_t state) const {
        return lv_image_src_get_type(
            &reinterpret_cast<const lv_imagebutton_t*>(this->raw_ptr())->src_mid[state]);
    }

    lv_image_src_t ImageButton::get_src_right_type(lv_imagebutton_state_t state) const {
        return lv_image_src_get_type(
            &reinterpret_cast<const lv_imagebutton_t*>(this->raw_ptr())->src_right[state]);
    }

    const ImageDescriptor ImageButton::get_src_left_img(lv_imagebutton_state_t state) const {
        assert(this->get_src_left_type(state) == LV_IMAGE_SRC_VARIABLE);
        return ImageDescriptor(
            const_cast<lv_img_dsc_t*>(reinterpret_cast<const lv_img_dsc_t*>(
                &reinterpret_cast<const lv_imagebutton_t*>(this->raw_ptr())->src_left[state]
            )
        ));
    }

    const std::string ImageButton::get_src_left_str(lv_imagebutton_state_t state) const {
        auto src_type = this->get_src_left_type(state);
        assert(src_type == LV_IMAGE_SRC_FILE || src_type == LV_IMAGE_SRC_SYMBOL);
        return std::string(
            const_cast<char*>(reinterpret_cast<const char*>(
                &reinterpret_cast<const lv_imagebutton_t*>(this->raw_ptr())->src_left[state]
            )
        ));
    }

    const ImageDescriptor ImageButton::get_src_mid_img(lv_imagebutton_state_t state) const {
        assert(this->get_src_mid_type(state) == LV_IMAGE_SRC_VARIABLE);
        return ImageDescriptor(
            const_cast<lv_img_dsc_t*>(reinterpret_cast<const lv_img_dsc_t*>(
                &reinterpret_cast<const lv_imagebutton_t*>(this->raw_ptr())->src_mid[state]
            )
        ));
    }

    const std::string ImageButton::get_src_mid_str(lv_imagebutton_state_t state) const {
        auto src_type = this->get_src_mid_type(state);
        assert(src_type == LV_IMAGE_SRC_FILE || src_type == LV_IMAGE_SRC_SYMBOL);
        return std::string(
            const_cast<char*>(reinterpret_cast<const char*>(
                &reinterpret_cast<const lv_imagebutton_t*>(this->raw_ptr())->src_mid[state]
            )
        ));
    }

    const ImageDescriptor ImageButton::get_src_right_img(lv_imagebutton_state_t state) const {
        assert(this->get_src_right_type(state) == LV_IMAGE_SRC_VARIABLE);
        return ImageDescriptor(
            const_cast<lv_img_dsc_t*>(reinterpret_cast<const lv_img_dsc_t*>(
                &reinterpret_cast<const lv_imagebutton_t*>(this->raw_ptr())->src_right[state]
            )
        ));
    }

    const std::string ImageButton::get_src_right_str(lv_imagebutton_state_t state) const {
        auto src_type = this->get_src_right_type(state);
        assert(src_type == LV_IMAGE_SRC_FILE || src_type == LV_IMAGE_SRC_SYMBOL);
        return std::string(
             const_cast<char*>(reinterpret_cast<const char*>(
                 &reinterpret_cast<const lv_imagebutton_t*>(this->raw_ptr())->src_right[state]
             )
        ));
    }

}
#endif // LV_USE_IMAGEBUTTON