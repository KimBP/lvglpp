#include "lvglpp/core/display.h" // for scr_act()
#include "lvglpp/widgets/chart/chart.h" // for Chart
#include "lvglpp/widgets/label/label.h" // for Label
#include "lvglpp/core/event.h" // for Event
#include "lvglpp/misc/txt.h" // for text functions
#include "lvglpp/misc/color.h" // for colors
#include "lvglpp/draw/desc.h" // For Draw descriptor

namespace lvgl::examples {
    
    using namespace lvgl::core;
    using namespace lvgl::widgets;
    using namespace lvgl::misc;
    
    static lv_chart_series_t * ser;
    static lv_chart_cursor_t * cursor;

    static void value_changed_event_cb(Event & e) {
        static int32_t last_id = -1;
        auto obj = e.get_target<Chart>();
        last_id = obj.get_selected_point();
        if(last_id != LV_CHART_POINT_NONE) {
            obj.set_cursor_point(cursor, last_id);
        }
    }

    void chart_6() {
        auto root = scr_act();
        static auto chart = Chart(root);

        chart.set_size(200, 150);
        chart.align(LV_ALIGN_CENTER, 0, -10);

        chart.add_event_cb(value_changed_event_cb, LV_EVENT_VALUE_CHANGED);
        chart.refresh_ext_draw_size();

        cursor = chart.add_cursor(palette::main(Color::Blue), static_cast<lv_dir_t>(LV_DIR_LEFT | LV_DIR_BOTTOM));

        ser = chart.add_series(palette::main(Color::Red), LV_CHART_AXIS_PRIMARY_Y);
        for(uint32_t i = 0; i < 10; i++)
            chart.set_next_y_value(ser, lv_rand(10, 90));

        static auto label = Label(root);
        label.set_text("Click on a point");
        label.align_to(chart, LV_ALIGN_OUT_TOP_MID, 0, -5);
    }
}