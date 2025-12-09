add_subdirectory(raylib)

add_library(vendor INTERFACE)

target_include_directories(vendor INTERFACE raygui/src)

target_link_libraries(vendor INTERFACE raylib)
