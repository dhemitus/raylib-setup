cmake_minimum_required(VERSION 4.0)

project(RaylibTemplate)

set(CMAKE_C_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_subdirectory(vendor/raylib)

file(GLOB_RECURSE SOURCES "src/*.c")
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE vendor/raylib/src)

target_include_directories(${PROJECT_NAME} PRIVATE vendor/raygui/src)

target_link_libraries(${PROJECT_NAME} raylib)

target_compile_definitions(${PROJECT_NAME}
                           PUBLIC ASSET_PATH="${CMAKE_CURRENT_SOURCE_DIR}/res/")
