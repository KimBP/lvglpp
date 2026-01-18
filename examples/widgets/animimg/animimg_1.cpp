#include "lvglpp/core/display.h" // for scr_act()
#include "lvglpp/widgets/animimg/animimg.h" // for AnimatedImage
#include "lvglpp/draw/image.h" // for ImageDescriptor

LV_IMG_DECLARE(animimg001);
LV_IMG_DECLARE(animimg002);
LV_IMG_DECLARE(animimg003);

namespace lvgl::examples {
    
    using namespace lvgl::core;
    using namespace lvgl::widgets;
    
    void animimg_1() {
        static std::vector<ImageDescriptor> anim_imgs(3);

        anim_imgs[0].set_src(animimg001);
        anim_imgs[1].set_src(animimg002);
        anim_imgs[2].set_src(animimg003);

        static auto animimg = AnimatedImage(scr_act());
        animimg.center();
        animimg.set_src(anim_imgs);
        animimg.set_duration(1000);
        animimg.set_repeat_count(LV_ANIM_REPEAT_INFINITE);
        animimg.start();
    }
}