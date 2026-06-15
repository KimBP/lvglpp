/** \file desc.cpp
 *  \brief Implementation file for C++ wrapper for LVGL draw descriptors.
 *
 *  Author: Vincent Paeder
 *  License: MIT
 */
#include "desc.h"
#include "../font/font.h"
#include "../draw/layer.h"

namespace lvgl::draw {

    BaseDrawDescriptor::BaseDrawDescriptor(lv_draw_dsc_base_t * descriptor) {
        this->owns_ptr = false;
        this->lv_obj = LvPointer<lv_draw_dsc_base_t, lv_free>(descriptor);
    }

    lv_part_t BaseDrawDescriptor::part() {
        return static_cast<lv_part_t>(this->raw_ptr()->part);
    }

    uint32_t BaseDrawDescriptor::id1() {
        return this->raw_ptr()->id1;
    }

    uint32_t BaseDrawDescriptor::id2() {
        return this->raw_ptr()->id2;
    }

    Layer BaseDrawDescriptor::layer() {
        return Layer(this->raw_ptr()->layer);
    }

    RectangleDrawDescriptor::RectangleDrawDescriptor() {
        this->lv_obj = LvPointerType(lv_cls_alloc<lv_cls>());
        lv_draw_rect_dsc_init(this->raw_ptr());
    }

    void RectangleDrawDescriptor::draw(Layer & layer, const Area & coords) {
        lv_draw_rect(layer.raw_ptr(), this->raw_ptr(), coords.raw_ptr());
    }


    LabelDrawDescriptor::LabelDrawDescriptor() {
        this->lv_obj = LvPointerType(lv_cls_alloc<lv_cls>());
        lv_draw_label_dsc_init(this->raw_ptr());
    }

    LabelDrawDescriptor::LabelDrawDescriptor(lv_draw_label_dsc_t * descriptor) {
        this->owns_ptr = false;
        this->lv_obj = LvPointer<lv_draw_label_dsc_t, lv_free>(descriptor);
    }

    void LabelDrawDescriptor::draw(Layer & layer, const Area & coords) {
        lv_draw_label(layer.raw_ptr(), this->raw_ptr(), coords.raw_ptr());
    }

    LetterDrawDescriptor::LetterDrawDescriptor() {
        this->lv_obj = LvPointerType(lv_cls_alloc<lv_cls>());
        lv_draw_letter_dsc_init(this->raw_ptr());
    }

    void LetterDrawDescriptor::draw(Layer & layer, const lv_point_t & pos) {
        lv_draw_letter(layer.raw_ptr(), this->raw_ptr(), &pos);
    }


    ImageDrawDescriptor::ImageDrawDescriptor() {
        this->lv_obj = LvPointerType(lv_cls_alloc<lv_cls>());
        lv_draw_image_dsc_init(this->raw_ptr());
    }

    void ImageDrawDescriptor::draw(Layer & layer, const Area & coords) {
        lv_draw_image(layer.raw_ptr(), this->raw_ptr(), coords.raw_ptr());
    }


    LineDrawDescriptor::LineDrawDescriptor() {
        this->lv_obj = LvPointerType(lv_cls_alloc<lv_cls>());
        lv_draw_line_dsc_init(this->raw_ptr());
    }

    void LineDrawDescriptor::draw(Layer & layer) {
        lv_draw_line(layer.raw_ptr(), this->raw_ptr());
    }


    ArcDrawDescriptor::ArcDrawDescriptor() {
        this->lv_obj = LvPointerType(lv_cls_alloc<lv_cls>());
        lv_draw_arc_dsc_init(this->raw_ptr());
    }

    void ArcDrawDescriptor::draw(Layer & layer) {
        lv_draw_arc(layer.raw_ptr(), this->raw_ptr());
    }

    FillDrawDescriptor::FillDrawDescriptor() {
        this->lv_obj = LvPointerType(lv_cls_alloc<lv_cls>());
        lv_draw_fill_dsc_init(this->raw_ptr());
    }

    FillDrawDescriptor::FillDrawDescriptor(lv_draw_fill_dsc_t* descriptor) {
        this->owns_ptr = false;
        this->lv_obj = LvPointer<lv_draw_fill_dsc_t, lv_free>(descriptor);
    }

    void FillDrawDescriptor::draw(Layer & layer, const Area & coords) {
        lv_draw_fill(layer.raw_ptr(), this->raw_ptr(), coords.raw_ptr());
    }

    BoxShadowDrawDescriptor::BoxShadowDrawDescriptor() {
        this->lv_obj = LvPointerType(lv_cls_alloc<lv_cls>());
        lv_draw_box_shadow_dsc_init(this->raw_ptr());
    }

    BoxShadowDrawDescriptor::BoxShadowDrawDescriptor(lv_draw_box_shadow_dsc_t * descriptor) {
        this->owns_ptr = false;
        this->lv_obj = LvPointer<lv_draw_box_shadow_dsc_t, lv_free>(descriptor);
    }

    void BoxShadowDrawDescriptor::draw(Layer & layer, const Area & coords) {
        lv_draw_box_shadow(layer.raw_ptr(), this->raw_ptr(), coords.raw_ptr());
    }
}