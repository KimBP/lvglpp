#include "lvglpp/core/display.h" // for scr_act()
#include "lvglpp/widgets/canvas/canvas.h" // for Canvas
#include "lvglpp/misc/color.h" // for colors
#include "lvglpp/draw/desc.h" // for Draw descriptor
#include "lvglpp/draw/draw_buf.h" // for DrawBuf

#define CANVAS_WIDTH  200U
#define CANVAS_HEIGHT  150U

namespace lvgl::examples {
    
    using namespace lvgl::core;
    using namespace lvgl::widgets;
    using namespace lvgl::misc;

    void canvas_1() {
        RectangleDrawDescriptor rect_dsc;
        rect_dsc->radius = 10;
        rect_dsc->bg_opa = LV_OPA_COVER;
        rect_dsc->bg_grad.dir = LV_GRAD_DIR_VER;
        rect_dsc->bg_grad.stops[0].color = palette::main(Color::Red);
        rect_dsc->bg_grad.stops[0].opa = LV_OPA_100;
        rect_dsc->bg_grad.stops[1].color = palette::main(Color::Blue);
        rect_dsc->bg_grad.stops[1].opa = LV_OPA_50;
        rect_dsc->border_width = 2;
        rect_dsc->border_opa = LV_OPA_90;
        rect_dsc->border_color = palette::white();
        rect_dsc->shadow_width = 5;
        rect_dsc->shadow_offset_x = 5;
        rect_dsc->shadow_offset_y = 5;

        LabelDrawDescriptor label_dsc;
        label_dsc->color = palette::main(Color::Orange);
        label_dsc->text = "Some text on text canvas";

        // Create a buffer for the canvas
        static std::vector<uint8_t> buf_16(LV_DRAW_BUF_STRIDE(CANVAS_WIDTH, LV_COLOR_FORMAT_RGB565) * CANVAS_HEIGHT);
        DrawBuf draw_buf_16 {CANVAS_WIDTH, CANVAS_HEIGHT, LV_COLOR_FORMAT_RGB565, LV_DRAW_BUF_STRIDE(CANVAS_WIDTH, LV_COLOR_FORMAT_RGB565), buf_16};

        Canvas canvas {scr_act()};
        canvas.set_buffer(draw_buf_16);
        canvas.center();
        canvas.fill_bg(palette::light(Color::Grey, 3), LV_OPA_COVER);
        
        Layer layer;
        canvas.init_layer(layer);

        Area coords_rect{30 ,20, 70, 50};
        rect_dsc.draw(layer, coords_rect);

        Area coords_text{40, 80, 60, 40};
        label_dsc.draw(layer, coords_text);

        canvas.finish_layer(layer);

        canvas.release_ptr();

        /*Test the rotation. It requires another buffer where the original image is stored.
        *So copy the current image to buffer and rotate it to the canvas*/
        static std::vector<uint8_t> buf_32(LV_DRAW_BUF_STRIDE(CANVAS_WIDTH, LV_COLOR_FORMAT_ARGB8888) * CANVAS_HEIGHT);
        DrawBuf draw_buf_32 {CANVAS_WIDTH, CANVAS_HEIGHT, LV_COLOR_FORMAT_ARGB8888, LV_DRAW_BUF_STRIDE(CANVAS_WIDTH, LV_COLOR_FORMAT_ARGB8888), buf_32};

        Canvas canvas2 {scr_act()};
        canvas2.set_buffer(draw_buf_32);
        canvas2.fill_bg(lv_color_hex3(0xccc), LV_OPA_COVER);
        canvas2.center();
        canvas2.fill_bg(palette::light(Color::Grey, 1), LV_OPA_COVER);
        canvas2.init_layer(layer);

        ImageDescriptor img;
        draw_buf_16.to_image(img);

        ImageDrawDescriptor img_draw_dsc;
        img_draw_dsc->rotation = 120;
        img_draw_dsc->src = img.raw_ptr();
        img.release_ptr(); // img_draw_dsc needs raw image. Avoid it becomes freed

        img_draw_dsc->pivot.x = CANVAS_WIDTH / 2;
        img_draw_dsc->pivot.y = CANVAS_HEIGHT / 2;

        Area coords_img{0, 0, CANVAS_WIDTH, CANVAS_HEIGHT};
        img_draw_dsc.draw(layer, coords_img);

        canvas2.finish_layer(layer);

        draw_buf_16.release_ptr();
        draw_buf_32.release_ptr();
        canvas2.release_ptr();
    }
}