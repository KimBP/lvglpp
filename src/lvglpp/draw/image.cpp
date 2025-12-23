/** \file image.cpp
 *  \brief Implementation file for C++ wrapper for low-level image-handling
 *  LVGL objects, such as lv_img_decoder_dsc_t, lv_img_header_t and lv_img_dsc_t.
 *
 *  Author: Vincent Paeder
 *  License: MIT
 */
#include "image.h"

namespace lvgl::draw {
    
    ImageDecoder::ImageDecoder(const ImageDescriptor & src, const lv_image_decoder_args_t * args) {
        lv_image_decoder_open(this->raw_ptr(), src.raw_ptr(), args);
    }

    ImageHeader ImageDecoder::get_info(const ImageDescriptor & src) {
        auto header = ImageHeader(lv_cls_alloc<lv_image_header_t>());
        auto res = lv_image_decoder_get_info(src.raw_ptr(), header.raw_ptr());
        header.is_valid(res == LV_RES_OK);
        return header;
    }

    ImageHeader ImageDecoder::get_info(const std::string & src) {
        auto header = ImageHeader(lv_cls_alloc<lv_image_header_t>());
        auto res = lv_image_decoder_get_info(src.c_str(), header.raw_ptr());
        header.is_valid(res == LV_RES_OK);
        return header;
    }

#ifdef MISSING_PORT
    lv_res_t ImageDecoder::read_line(lv_coord_t x, lv_coord_t y, lv_coord_t len, std::vector<uint8_t> & buf) {
        return lv_image_decoder_read_line(this->raw_ptr(), x, y, len, buf.data());
    }
#endif

    void ImageDecoder::close() {
        lv_image_decoder_close(this->raw_ptr());
    }


    bool ImageHeader::is_valid() const {
        return this->valid;
    }

    void ImageHeader::is_valid(bool valid) {
        this->valid = valid;
    }

    Area ImageHeader::area() const {
        if ( this->valid) {
            return Area(0,0,this->raw_ptr()->w, this->raw_ptr()->h);
        } else {
            return Area();
        }
    }

    ImageDescriptor::ImageDescriptor() {
        this->lv_obj = LvPointer<lv_image_dsc_t, lv_image_buf_free>(lv_cls_alloc<lv_image_dsc_t>());
    }

    ImageDescriptor::ImageDescriptor(lv_coord_t w, lv_coord_t h, lv_color_format_t cf) {
        this->lv_obj =
            LvPointer<lv_image_dsc_t, lv_image_buf_free>(static_cast<lv_image_dsc_t*>(
                static_cast<void*>(lv_draw_buf_create(w, h, cf, 0))));
    }

    ImageDescriptor::ImageDescriptor(const lv_img_dsc_t * dsc) {
        this->lv_obj = LvPointer<lv_image_dsc_t, lv_image_buf_free>(lv_cls_alloc<lv_image_dsc_t>());
        lv_memcpy(this->raw_ptr(), dsc, sizeof(lv_image_dsc_t));
    }

#ifdef MISSING_PORT
    lv_color_t ImageDescriptor::get_px_color(lv_coord_t x, lv_coord_t y, lv_color_t bg_color) const {
        return lv_img_buf_get_px_color(const_cast<lv_cls_ptr>(this->raw_ptr()), x, y, bg_color);
    }

    lv_opa_t ImageDescriptor::get_px_alpha(lv_coord_t x, lv_coord_t y) const {
        return lv_img_buf_get_px_alpha(const_cast<lv_cls_ptr>(this->raw_ptr()), x, y);
    }

    void ImageDescriptor::set_px_color(lv_coord_t x, lv_coord_t y, lv_color_t c) {
        lv_img_buf_set_px_color(this->raw_ptr(), x, y, c);
    }
    
    void ImageDescriptor::set_px_alpha(lv_coord_t x, lv_coord_t y, lv_opa_t opa) {
        lv_img_buf_set_px_alpha(this->raw_ptr(), x, y, opa);
    }
#endif

    void ImageDescriptor::set_palette(uint8_t id, lv_color_t c) {
        lv_color32_t c32{.blue = c.blue, .green = c.green, .red = c.red, .alpha = 255};
        lv_image_buf_set_palette(this->raw_ptr(), id, c32);
    }

    void ImageDescriptor::set_palette(uint8_t id, lv_color32_t c) {
        lv_image_buf_set_palette(this->raw_ptr(), id, c);
    }

#ifdef MISSING_PORT
    uint32_t ImageDescriptor::get_img_size(lv_coord_t w, lv_coord_t h, lv_color_format_t cf) const {
        return lv_img_buf_get_img_size(w, h, cf);
    }
#endif

    void ImageDescriptor::set_src(const lv_image_dsc_t & dsc) {
        lv_memcpy(this->raw_ptr(), &dsc, sizeof(lv_image_dsc_t));
    }

    void ImageDescriptor::set_src(const lv_image_dsc_t * dsc) {
        lv_memcpy(this->raw_ptr(), dsc, sizeof(lv_image_dsc_t));
    }

}