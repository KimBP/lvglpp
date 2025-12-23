#include "lvglpp/core/display.h" // for scr_act()
#include "lvglpp/widgets/bar/bar.h" // for Bar
#include "lvglpp/misc/style.h" // for Style
#include "lvglpp/misc/anim.h" // for Animation
#include "lvglpp/misc/txt.h" // for text functions
#include "lvglpp/core/event.h" // for Event
#include "lvglpp/draw/desc.h" // for Draw descriptor
#include <string>

#define MAX_VALUE 100
#define MIN_VALUE 0

namespace lvgl::examples {
    
    using namespace lvgl::core;
    using namespace lvgl::widgets;
    using namespace lvgl::misc;
    
    static void event_cb(Event & e) {
        auto obj = e.get_target<Bar>();

        LabelDrawDescriptor label_dsc;
        label_dsc->font = LV_FONT_DEFAULT;
        
        auto txt = std::to_string(obj.get_value());
        auto txt_size = txt::get_size(txt, label_dsc->font, label_dsc->letter_space,
                                      label_dsc->line_space, LV_COORD_MAX, label_dsc->flag);

        Area txt_area;
        txt_area->x1 = 0;
        txt_area->x2 = txt_size.x - 1;
        txt_area->y1 = 0;
        txt_area->y2 = txt_size.y - 1;

        Area indic_area(obj.get_coords());
        indic_area.set_width(indic_area.get_width() * obj.get_value() / MAX_VALUE);

        /*If the indicator is long enough put the text inside on the right*/
        if(indic_area.get_width() > txt_size.x + 20) {
            indic_area.align_to(txt_area, LV_ALIGN_RIGHT_MID, -10, 0);
            label_dsc->color = palette::white();
        }
        /*If the indicator is too short put the text out of it on the right*/
        else {
            indic_area.align_to(txt_area, LV_ALIGN_OUT_RIGHT_MID, 10, 0);
            label_dsc->color = palette::black();
        }

        auto layer = e.get_layer();
        label_dsc.draw(layer, txt_area);
    }

    void bar_6() {
        static auto bar = Bar(scr_act());
        bar.add_event_cb(event_cb, LV_EVENT_DRAW_MAIN_END);
        bar.set_range(MIN_VALUE, MAX_VALUE);
        bar.set_size(200, 20);
        bar.center();

        static Animation a;
        a.set_var(bar);
        a.set_values(0, 100);
        auto set_value = [](Bar & bar, int32_t v) {
            bar.set_value(v, LV_ANIM_OFF);
        };
        a.set_exec_cb<Bar>(set_value);
        a.set_time(2000);
        a.set_playback_duration(4000);
        a.set_reverse_duration(4000);
        a.set_repeat_count(LV_ANIM_REPEAT_INFINITE);
        a.start();
   }

}