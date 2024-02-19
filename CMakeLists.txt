cmake_minimum_required(VERSION 3.14)
project(dec_to_bin)

add_executable(${PROJECT_NAME} main.cpp)

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
    CMAKE_CXX_STANDARD 17
)