/** \file layer.cpp
 *  \brief Implementation file for C++ wrapper for layer routines.
 *
 *  Author: Kim Bøndergaard
 *  License: MIT
 */
#include "layer.h"

namespace lvgl::draw {

    Layer::Layer() {
        this->lv_obj = LvPointerType(lv_cls_alloc<lv_cls>());
    }

    Layer::Layer(lv_color_format_t cf, const Area & area) {
        this->lv_obj = LvPointerType(lv_cls_alloc<lv_cls>());
        lv_draw_layer_init(this->raw_ptr(), nullptr, cf, area.raw_ptr());

        lv_draw_layer_alloc_buf(this->raw_ptr());
    }


    Layer::Layer(Layer & parent, lv_color_format_t cf, const Area & area) {
        this->lv_obj = LvPointerType(lv_cls_alloc<lv_cls>());
        lv_draw_layer_init(this->raw_ptr(), parent.raw_ptr(), cf, area.raw_ptr());

        this->raw_ptr()->opa = parent.raw_ptr()->opa;
        this->raw_ptr()->recolor = parent.raw_ptr()->recolor;

        lv_draw_layer_alloc_buf(this->raw_ptr());
    }

    Layer::Layer(lv_layer_t * layer) {
        this->owns_ptr = false;
        this->lv_obj = LvPointer<lv_layer_t, lv_free>(layer);
    }

    void Layer::reset() {
        lv_layer_reset(this->raw_ptr());
    }

    void * Layer::go_to_xy(int32_t x, int32_t y) {
        return lv_draw_layer_go_to_xy(this->raw_ptr(), x, y);
    }

    bool Layer::dispatch(Display & display)
    {
        return lv_draw_dispatch_layer(display.raw_ptr(), this->raw_ptr());
    }

    void Layer::finalize_task_creation(DrawTask & drawTask) {
        lv_draw_finalize_task_creation(this->raw_ptr(), drawTask.raw_ptr());
    }


    DrawTask Layer::get_available_task(uint8_t draw_unit_id)
    {
        return DrawTask(lv_draw_get_available_task(this->raw_ptr(), nullptr, draw_unit_id));
    }

    DrawTask Layer::get_available_task(DrawTask & prev, uint8_t draw_unit_id)
    {
        return DrawTask(lv_draw_get_available_task(this->raw_ptr(), prev.raw_ptr(), draw_unit_id));
    }

    DrawTask Layer::get_next_available_task(uint8_t draw_unit_id)
    {
        return DrawTask(lv_draw_get_next_available_task(this->raw_ptr(), nullptr, draw_unit_id));
    }

    DrawTask Layer::get_next_available_task(DrawTask & prev, uint8_t draw_unit_id)
    {
        return DrawTask(lv_draw_get_next_available_task(this->raw_ptr(), prev.raw_ptr(), draw_unit_id));
    }

    DrawTask Layer::add_task(const Area & area, lv_draw_task_type_t taskType) {
        auto drawTask = lv_draw_add_task(this->raw_ptr(), area.raw_ptr(), taskType);
        return DrawTask(drawTask);
    }


}
