#include "lvglpp/core/display.h" // for scr_act()
#include "lvglpp/misc/style.h" // for Style
#include "lvglpp/misc/color.h" // for colors
#include "lvglpp/widgets/image/image.h" // for Image

LV_IMG_DECLARE(img_cogwheel_argb);

namespace lvgl::examples {
    
    using namespace lvgl::core;
    using namespace lvgl::misc;
    using namespace lvgl::widgets;

    void style_6() {
        static Style style;
        /*Set a background color and a radius*/
        style.set_radius(5);
        style.set_bg_opa(LV_OPA_COVER);
        style.set_bg_color(palette::light(Color::Grey, 3));
        style.set_border_width(2);
        style.set_border_color(palette::main(Color::Blue));

        style.set_img_recolor(palette::main(Color::Blue));
        style.set_img_recolor_opa(LV_OPA_50);
        style.set_transform_angle(300);
        
        /*Create an object with the new style*/
        static auto obj = Image(scr_act());
        obj.add_style(style, LV_STATE_DEFAULT);
        static auto img_cogwheel_desc = ImageDescriptor(&img_cogwheel_argb);
        obj.set_src(img_cogwheel_desc);
        obj.center();
    }
}