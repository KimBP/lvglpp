#include "lvglpp/core/display.h" // for scr_act()
#include "lvglpp/widgets/label/label.h" // for Label
#include "lvglpp/widgets/canvas/canvas.h" // for Canvas
#include "lvglpp/draw/desc.h" // for LabelDrawDescriptor
#include "lvglpp/draw/draw_buf.h" // For DrawMask
#include "lvglpp/misc/color.h" // for colors
#include "lvglpp/draw/layer.h"

namespace lvgl::examples {
    
    using namespace lvgl::core;
    using namespace lvgl::widgets;
    using namespace lvgl::draw;
    using namespace lvgl::misc;

    #define MASK_WIDTH 150
    #define MASK_HEIGHT 60

    /* Create the mask of a text by drawing it to a canvas*/
    static void generate_mask(DrawBuf & mask, const std::string& text)
    {
        Canvas canvas;

        canvas.set_buffer(mask);
        canvas.fill_bg(palette::black(), LV_OPA_TRANSP);

        Layer layer;
        canvas.init_layer(layer);

        LabelDrawDescriptor label_dsc;

        label_dsc->color = palette::white();
        label_dsc->align = LV_TEXT_ALIGN_CENTER;
        label_dsc->text = text.c_str();
        label_dsc->font = &lv_font_montserrat_24;

        auto area = mask.get_area();

        label_dsc.draw(layer, area);

        label_dsc.release_ptr();

        canvas.finish_layer(layer);

        layer.release_ptr();

    }
    void label_4() {
        /* Create the mask of a text by drawing it to a canvas*/
        static std::vector<lv_opa_t> mask_map(DrawBuf::width_to_stride(MASK_WIDTH, LV_COLOR_FORMAT_L8) * MASK_HEIGHT);
        static DrawBuf mask (MASK_WIDTH, MASK_HEIGHT, LV_COLOR_FORMAT_L8,
                        DrawBuf::width_to_stride(MASK_WIDTH, LV_COLOR_FORMAT_L8), mask_map);
        mask.set_flag(LV_IMAGE_FLAGS_MODIFIABLE);

        generate_mask(mask, "Text with gradient");

        /* Create an object from where the text will be masked out.
        * Now it's a rectangle with a gradient but it could be an image too*/
        Container grad(screen_active());

        grad.set_size(MASK_WIDTH, MASK_HEIGHT);
        grad.center();
        grad.set_style_bg_color(lv_color_hex(0xff0000), 0);
        grad.set_style_bg_grad_color(lv_color_hex(0x0000ff), 0);
        grad.set_style_bg_grad_dir(LV_GRAD_DIR_HOR, 0);
        grad.set_style_bitmap_mask_src(mask, 0);

        grad.release_ptr();
    }
}