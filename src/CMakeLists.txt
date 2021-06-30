add_executable(n5gui main.c)

target_link_libraries(n5gui LINK_PUBLIC lvgl)
target_link_libraries(n5gui LINK_PUBLIC lv_drivers)
target_link_libraries(n5gui LINK_PUBLIC lv_examples)