#include "lvglpp/core/display.h" // for scr_act()
#include "lvglpp/widgets/table/table.h" // for Table
#include "lvglpp/widgets/label/label.h" // for Label
#include "lvglpp/core/event.h" // for Event
#include "lvglpp/misc/color.h" // for colors
#include "lvglpp/draw/desc.h" // For Draw descriptor

namespace lvgl::examples {
    
    using namespace lvgl::core;
    using namespace lvgl::widgets;
    using namespace lvgl::misc;

    #define ITEM_CNT 200

    static void draw_event_cb(Event & e) {
        auto obj = e.get_target<Table>();
        auto draw_task = e.get_draw_task();
        auto dsc = draw_task.getBaseDescriptor();
        /*If the cells are drawn...*/
        if(dsc->part() == LV_PART_ITEMS && draw_task.get_type() == LV_DRAW_TASK_TYPE_FILL) {
            // Draw background
            bool chk = obj.has_cell_ctrl(dsc->id1(), 0, LV_TABLE_CELL_CTRL_CUSTOM_1);
            auto layer = dsc->layer();

            RectangleDrawDescriptor rect_dsc;
            rect_dsc->bg_color = chk ? obj.get_color_primary() : palette::light(Color::Grey, 2);
            rect_dsc->radius = LV_RADIUS_CIRCLE;

            Area sw_area;
            sw_area.set(0,0,40,24);

            auto draw_task_area = draw_task.get_area();
            sw_area.align_to(draw_task_area, LV_ALIGN_RIGHT_MID, -15, 0);
            rect_dsc.draw(layer, sw_area);

            // Draw the knob
            rect_dsc->bg_color = palette::white();
            Area knob_area;
            knob_area.set(0,0, 18, 18);
            if (chk) {
                knob_area.align_to(sw_area, LV_ALIGN_RIGHT_MID, -3, 0);
            } else {
                knob_area.align_to(sw_area, LV_ALIGN_LEFT_MID, 3, 0);
            }

            rect_dsc.draw(layer, knob_area);
        }
    }

    static void change_event_cb(Event & e)
    {
        auto obj = e.get_target<Table>();
        auto row = std::get<0>(obj.get_selected_cell());
        bool chk = obj.has_cell_ctrl(row, 0, LV_TABLE_CELL_CTRL_CUSTOM_1);
        if(chk) obj.clear_cell_ctrl(row, 0, LV_TABLE_CELL_CTRL_CUSTOM_1);
        else obj.add_cell_ctrl(row, 0, LV_TABLE_CELL_CTRL_CUSTOM_1);
    }

    void table_2() {
        /*Measure memory usage*/
        lv_mem_monitor_t mon1;
        lv_mem_monitor(&mon1);

        uint32_t t = lv_tick_get();

        auto root = scr_act();
        
        static auto table = Table(root);

        /*Set a smaller height to the table. It'll make it scrollable*/
        table.set_size(LV_SIZE_CONTENT, 200);

        table.set_col_width(0, 150);
        table.set_row_cnt(ITEM_CNT); /*Not required but avoids a lot of memory reallocation lv_table_set_set_value*/
        table.set_col_cnt(1);

        /*Don't make the cell pressed, we will draw something different in the event*/
        table.remove_style(LV_PART_ITEMS | LV_STATE_PRESSED);

        for(uint32_t i = 0; i < ITEM_CNT; i++) {
            table.set_cell_value_fmt(i, 0, "Item %u", i + 1);
        }

        table.align(LV_ALIGN_CENTER, 0, -20);

        /*Add an event callback to to apply some custom drawing*/
        table.add_event_cb(draw_event_cb, LV_EVENT_DRAW_TASK_ADDED);
        table.add_event_cb(change_event_cb, LV_EVENT_VALUE_CHANGED);
        table.add_flag(LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS);

        lv_mem_monitor_t mon2;
        lv_mem_monitor(&mon2);

        uint32_t mem_used = mon1.free_size - mon2.free_size;

        uint32_t elaps = lv_tick_elaps(t);

        static auto label = Label(root);
        label.set_text_fmt("%u items were created in %u ms\n"
                           "using %u bytes of memory",
                           ITEM_CNT, elaps, mem_used);

        label.align(LV_ALIGN_BOTTOM_MID, 0, -10);
    }
}