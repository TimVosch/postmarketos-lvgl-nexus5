#include "lvgl/lvgl.h"
#include "lv_drivers/display/fbdev.h"
#include "lv_examples/lv_examples.h"
#include <unistd.h>

int main(void)
{
  /*LittlevGL init*/
  lv_init();

  /*Linux frame buffer device init*/
  fbdev_init();

  static lv_disp_buf_t disp_buf;
  static lv_color_t buf[1080 * 1920 / 10];
  lv_disp_buf_init(&disp_buf, buf, NULL, 1080 * 1920 / 10);

  lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.flush_cb = fbdev_flush;
  disp_drv.buffer = &disp_buf;
  disp_drv.hor_res = 1080;
  disp_drv.ver_res = 1920;
  lv_disp_drv_register(&disp_drv);

  lv_demo_widgets();

  while (1)
  {
    lv_tick_inc(1);
    lv_task_handler();
    usleep(1000);
  }

  return 0;
}