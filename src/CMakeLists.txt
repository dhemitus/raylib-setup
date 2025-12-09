file(GLOB_RECURSE SOURCES "*.c")
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
