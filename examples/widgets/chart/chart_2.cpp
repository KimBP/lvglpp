#include "lvglpp/core/display.h" // for scr_act()
#include "lvglpp/widgets/chart/chart.h" // for Chart
#include "lvglpp/misc/timer.h" // for Timer
#include "lvglpp/misc/color.h" // for colors
#include "lvglpp/core/event.h" // for Event
#include "lvglpp/draw/mask.h" // for mask functions
#include "lvglpp/draw/desc.h" // for Draw descriptor
#include "lvglpp/widgets/scale/scale.h" // for Scale

namespace lvgl::examples {
    
    using namespace lvgl::core;
    using namespace lvgl::widgets;
    using namespace lvgl::misc;
    using namespace lvgl::draw;

    using SeriesPtr = lv_chart_series_t*;

    void chart_2() {
        Container main_cont{screen_active()};
        main_cont.set_size(200,150);
        main_cont.center();

        /* Create a transparent wrapper for the chart and the scale.
         * Set a large width, to make it scrollable on the main container */

        Container wrapper{main_cont};

        wrapper.remove_style_all();
        wrapper.set_size(lv_pct(300), lv_pct(100));
        wrapper.set_flex_flow(LV_FLEX_FLOW_COLUMN);

        /* Create a chart on the wrapper
         * Set it's width to 100% to fill the large wrapper */
        Chart chart{wrapper};

        chart.set_width(lv_pct(100));
        chart.set_flex_grow(1);
        chart.set_type(LV_CHART_TYPE_BAR);
        chart.set_axis_range(LV_CHART_AXIS_PRIMARY_Y, 0, 100);
        chart.set_axis_range(LV_CHART_AXIS_SECONDARY_Y, 0 , 400);
        chart.set_point_count(12);
        chart.set_style_radius(0,0);

        /* Create a scale also with 100% width*/
        Scale scale_bottom{wrapper};
        scale_bottom.set_mode(LV_SCALE_MODE_HORIZONTAL_BOTTOM);
        scale_bottom.set_size(lv_pct(100), 25);
        scale_bottom.set_total_tick_count(12);
        scale_bottom.set_major_tick_every(1);
        scale_bottom.set_style_pad_hor(chart.get_first_point_center_offset(), 0);

        static const char * month[]  = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                                        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec", 
                                        nullptr};
        scale_bottom.set_text_src(month);

        /* Add two data series*/
        auto ser1 = chart.add_series(palette::light(Color::Green, 2), LV_CHART_AXIS_PRIMARY_Y);
        auto ser2 = chart.add_series(palette::dark(Color::Green, 2), LV_CHART_AXIS_PRIMARY_Y);

        /*Set the next points on 'ser1' */
        for (uint32_t i = 0; i < 12; i++) {
            chart.set_next_y_value(ser1, static_cast<int32_t>(lv_rand(10,60)));
            chart.set_next_y_value(ser2, static_cast<int32_t>(lv_rand(50,90)));
        }

        chart.refresh(); /* Required after direct set */

        chart.release_ptr();
        wrapper.release_ptr();
        scale_bottom.release_ptr();
        main_cont.release_ptr();
    }
}