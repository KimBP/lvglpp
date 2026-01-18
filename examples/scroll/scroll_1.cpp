#include "lvglpp/core/display.h" // for scr_act()
#include "lvglpp/core/object.h" // for Container
#include "lvglpp/widgets/button/button.h" // for Button
#include "lvglpp/widgets/label/label.h" // for Label
#include "lvglpp/core/event.h" // for event

namespace lvgl::examples {
    
    using namespace lvgl::core;
    using namespace lvgl::widgets;

    using PanelPtr = std::unique_ptr<Container>;
    using ButtonPtr = std::unique_ptr<Button>;

    static PanelPtr panel;
    static ButtonPtr save_button;

    static int saved_scroll_x;
    static int saved_scroll_y;


    static void scroll_update_cb(Event & e) {
        LV_UNUSED(e);

        LV_LOG("scroll info: x:%3" LV_PRId32", y:%3" LV_PRId32", top:%3" LV_PRId32", "
            "bottom:%3" LV_PRId32", left:%3" LV_PRId32", right:%3" LV_PRId32"\n",
            panel->get_scroll_x(), panel->get_scroll_y(), panel->get_scroll_top(),
            panel->get_scroll_bottom(), panel->get_scroll_left(), panel->get_scroll_right());
    }

    static void button_event_cb(Event & e) {
        auto obj = e.get_target<Button>();
        if (*save_button == obj) {
            saved_scroll_x = panel->get_scroll_x();
            saved_scroll_y = panel->get_scroll_y();
        } else {
            panel->scroll_to(saved_scroll_x, saved_scroll_y, LV_ANIM_ON);
        }
    }

    void scroll_1() {
        /*Create an object with the new style*/
        panel = std::make_unique<Container>(screen_active());
        panel->set_size(200, 200);
        panel->align(LV_ALIGN_CENTER, 44, 0);

        auto child1 = Container(*panel);
        child1.set_pos(0, 0);
        child1.set_size(70, 70);

        auto label1 = Label(child1);
        label1.set_text("Zero");
        label1.center();

        label1.release_ptr();
        child1.release_ptr();

        auto child2 = Container(*panel);
        child2.set_pos(160, 80);
        child2.set_size(80, 80);

        auto btn = Button(child2);

        auto label2 = Label(btn);
        label2.set_text("Right");
        label2.center();

        label2.release_ptr();
        btn.release_ptr();
        child2.release_ptr();

        auto child3 = Container(*panel);
        child3.set_pos(40, 160);
        child3.set_size(100, 70);

        auto label3 = Label(child3);
        label3.center();

        label3.release_ptr();
        child3.release_ptr();

        // Call back called on scroll
        panel->add_event_cb(scroll_update_cb, LV_EVENT_SCROLL);

        // Save + Restore buttons
        save_button = std::make_unique<Button>(screen_active());

        auto lbl_save = Label(*save_button);
        lbl_save.set_text("Save");

        lbl_save.release_ptr();

        save_button->align_to(*panel, LV_ALIGN_OUT_LEFT_MID, -10, -20);
        save_button->add_event_cb(button_event_cb, LV_EVENT_CLICKED);

        auto restore_button = Button(screen_active());

        auto lbl_restore = Label(restore_button);
        lbl_restore.set_text("Restore");

        lbl_restore.release_ptr();

        restore_button.align_to(*panel, LV_ALIGN_OUT_LEFT_MID, -10, 20);
        restore_button.add_event_cb(button_event_cb, LV_EVENT_CLICKED);

        restore_button.release_ptr();

    }
}