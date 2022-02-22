cmake_minimum_required(VERSION 3.0)

project(yes_example)

add_subdirectory("./deps/yes")

add_executable(yes_example 
    "src/main.cpp"
)

target_link_libraries(yes_example PRIVATE yes)