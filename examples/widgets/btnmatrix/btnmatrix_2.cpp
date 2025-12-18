#include "lvglpp/core/display.h" // for scr_act()
#include "lvglpp/widgets/btnmatrix/btnmatrix.h" // for ButtonMatrix
#include "lvglpp/core/event.h" // for Event
#include "lvglpp/misc/style.h" // for Style
#include "lvglpp/misc/color.h" // for colors
#include "lvglpp/draw/desc.h" // for Draw descriptor
#include "lvglpp/draw/image.h" // for Image
#include <string>

LV_IMG_DECLARE(img_star);

namespace lvgl::examples {
    
    using namespace lvgl::core;
    using namespace lvgl::widgets;
    using namespace lvgl::misc;

    static void event_cb(Event & e) {
        auto obj = e.get_target<ButtonMatrix>();
        auto draw_task = e.get_draw_task();
        auto base_draw_dsc = draw_task.getBaseDescriptor();
        
        if (base_draw_dsc->part() == LV_PART_ITEMS) {
            bool pressed{false};

            if (obj.get_selected_btn() == base_draw_dsc->id1() && obj.has_state(LV_STATE_PRESSED)) {
                    pressed = true;
            }
            if (base_draw_dsc->id1() == 1) {
                // Btn2: Make it Blue, Give it a shadow, Make text white
                auto fill_draw_dsc = draw_task.get_draw_descriptor<FillDrawDescriptor>();
                if (fill_draw_dsc) {
                    fill_draw_dsc->raw_ptr()->radius = 0;
                    if (pressed) {
                        fill_draw_dsc->raw_ptr()->color = palette::dark(Color::Blue, 3); 
                    } else {
                        fill_draw_dsc->raw_ptr()->color = palette::main(Color::Blue);
                    }
                }

                auto box_shadow_draw_dsc = draw_task.get_draw_descriptor<BoxShadowDrawDescriptor>();
                if (box_shadow_draw_dsc) {
                    box_shadow_draw_dsc->raw_ptr()->width = 6;
                    box_shadow_draw_dsc->raw_ptr()->ofs_x = 3;
                    box_shadow_draw_dsc->raw_ptr()->ofs_y = 3;
                }

                auto label_draw_dsc = draw_task.get_draw_descriptor<LabelDrawDescriptor>();
                if (label_draw_dsc) {
                    label_draw_dsc->raw_ptr()->color = palette::white();
                }
            } else if (base_draw_dsc->id1() == 2) {
                // Btn3: Make it Red, Give it rounded ends
                auto fill_draw_dsc = draw_task.get_draw_descriptor<FillDrawDescriptor>();
                if (fill_draw_dsc) {
                    fill_draw_dsc->raw_ptr()->radius = LV_RADIUS_CIRCLE;
                    if (pressed) {
                        fill_draw_dsc->raw_ptr()->color = palette::dark(Color::Red, 3); 
                    } else {
                        fill_draw_dsc->raw_ptr()->color = palette::main(Color::Red);
                    }
                }

                auto box_shadow_draw_dsc = draw_task.get_draw_descriptor<BoxShadowDrawDescriptor>();
                if (box_shadow_draw_dsc) {
                    box_shadow_draw_dsc->raw_ptr()->radius = LV_RADIUS_CIRCLE;
                }
            } else if (base_draw_dsc->id1() == 3) {
                // Btn4: Add a star, make text invisible
                auto label_draw_dsc = draw_task.get_draw_descriptor<LabelDrawDescriptor>();
                if (label_draw_dsc) {
                    label_draw_dsc->raw_ptr()->opa = 0;
                }

                if (LV_DRAW_TASK_TYPE_FILL == draw_task.get_type()) {
                    auto img_dsc = ImageDescriptor(&img_star);

                    auto header = ImageDecoder::get_info(img_dsc);
                    auto area = header.area();

                    auto draw_task_area = draw_task.get_area();
                    area.align_to(draw_task_area, LV_ALIGN_CENTER, 0, 0);

                    auto layer = base_draw_dsc->layer();

                    ImageDrawDescriptor img_draw_dsc;

                    img_draw_dsc->recolor = palette::black();

                    if (pressed) img_draw_dsc->recolor_opa = LV_OPA_30;

                    img_draw_dsc.raw_ptr()->src = (void*)img_dsc.raw_ptr();
                    img_draw_dsc.draw(layer, area);

                    img_dsc.release_ptr();
                }
            }
        }
    }

    void btnmatrix_2() {
        static auto btnm = ButtonMatrix(scr_act());
        btnm.add_event_cb(event_cb, LV_EVENT_DRAW_TASK_ADDED);
        btnm.add_flag(LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS);
        btnm.center();
   }

}