cmake_minimum_required(VERSION 3.27)
project(vector-class CXX)

add_library(vector-class INTERFACE)

target_include_directories(vector-class INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)