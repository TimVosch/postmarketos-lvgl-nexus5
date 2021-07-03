#include "lvgl/lvgl.h"
#include "lv_drivers/display/fbdev.h"
#include "lv_drivers/indev/evdev.h"
#include "lv_demos/lv_examples.h"
#include <unistd.h>

int main(void)
{
  /*LittlevGL init*/
  lv_init();

  /*Linux frame buffer device init*/
  fbdev_init();

  evdev_init();

  static lv_disp_buf_t disp_buf;
  static lv_color_t buf1[1080 * 1920 / 10];
  static lv_color_t buf2[1080 * 1920 / 10];
  lv_disp_buf_init(&disp_buf, buf1, buf2, 1080 * 1920 / 10);

  lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.flush_cb = fbdev_flush;
  disp_drv.buffer = &disp_buf;
  disp_drv.hor_res = 1080;
  disp_drv.ver_res = 1920;
  lv_disp_drv_register(&disp_drv);

  lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = evdev_read;
  lv_indev_drv_register(&indev_drv);

  // lv_demo_widgets();
  lv_demo_printer();
  // lv_demo_music();
  // lv_demo_benchmark();
  // lv_demo_stress();

  while (1)
  {
    lv_tick_inc(5);
    lv_task_handler();
    usleep(5000);
  }

  return 0;
}