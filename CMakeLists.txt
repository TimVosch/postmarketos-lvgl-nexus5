cmake_minimum_required (VERSION 2.8.11)
project (N5G)

# =====================
# Cross compilation
# =====================

# =====================
# Sources and dependencies
# =====================

add_definitions(-DLV_DEMO_CONF_INCLUDE_SIMPLE -DLV_CONF_INCLUDE_SIMPLE -DLV_EX_CONF_INCLUDE_SIMPLE)

include_directories(include)
include_directories(lib)

add_subdirectory(lib)
add_subdirectory(src)
