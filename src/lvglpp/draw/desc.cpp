/** \file desc.cpp
 *  \brief Implementation file for C++ wrapper for LVGL draw descriptors.
 *
 *  Author: Vincent Paeder
 *  License: MIT
 */
#include "desc.h"
#include "../font/font.h"

namespace lvgl::draw {

    RectangleDrawDescriptor::RectangleDrawDescriptor() {
        this->lv_obj = LvPointerType(lv_cls_alloc<lv_cls>());
        lv_draw_rect_dsc_init(this->raw_ptr());
    }

    void RectangleDrawDescriptor::draw(lv_layer_t * draw_ctx, const Area & coords) {
        lv_draw_rect(draw_ctx, this->raw_ptr(), coords.raw_ptr());
    }


    LabelDrawDescriptor::LabelDrawDescriptor() {
        this->lv_obj = LvPointerType(lv_cls_alloc<lv_cls>());
        lv_draw_label_dsc_init(this->raw_ptr());
    }

    void LabelDrawDescriptor::draw(lv_layer_t * ctx, const Area & coords) {
        lv_draw_label(ctx, this->raw_ptr(), coords.raw_ptr());
    }

    LetterDrawDescriptor::LetterDrawDescriptor() {
        this->lv_obj = LvPointerType(lv_cls_alloc<lv_cls>());
        lv_draw_letter_dsc_init(this->raw_ptr());
    }

    void LetterDrawDescriptor::draw_letter(lv_layer_t * ctx, const lv_point_t & pos) {
        lv_draw_letter(ctx, this->raw_ptr(), &pos);
    }


    ImageDrawDescriptor::ImageDrawDescriptor() {
        this->lv_obj = LvPointerType(lv_cls_alloc<lv_cls>());
        lv_draw_image_dsc_init(this->raw_ptr());
    }

    void ImageDrawDescriptor::draw(lv_layer_t * ctx, const Area & coords) {
        lv_draw_image(ctx, this->raw_ptr(), coords.raw_ptr());
    }


    LineDrawDescriptor::LineDrawDescriptor() {
        this->lv_obj = LvPointerType(lv_cls_alloc<lv_cls>());
        lv_draw_line_dsc_init(this->raw_ptr());
    }

    void LineDrawDescriptor::draw(lv_layer_t * ctx) {
        lv_draw_line(ctx, this->raw_ptr());
    }


    ArcDrawDescriptor::ArcDrawDescriptor() {
        this->lv_obj = LvPointerType(lv_cls_alloc<lv_cls>());
        lv_draw_arc_dsc_init(this->raw_ptr());
    }

    void ArcDrawDescriptor::draw(lv_layer_t * ctx) {
        lv_draw_arc(ctx, this->raw_ptr());
    }
    
}