cmake_minimum_required(VERSION 4.0)

project(RaylibTemplate)

set(CMAKE_C_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_subdirectory(src)
add_subdirectory(vendor)
target_link_libraries(${PROJECT_NAME} vendor)
