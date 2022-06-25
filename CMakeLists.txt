cmake_minimum_required(VERSION 3.0)

project(yes_example)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory("./deps/yes")

add_executable(${PROJECT_NAME} 
    "src/main.cpp"
    "src/sandbox.h"
    "src/sandbox.cpp"
)

target_link_libraries(${PROJECT_NAME} PRIVATE "yes")

add_custom_target("copy-assets-folder" ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    ${CMAKE_BINARY_DIR}/assets
)
