cmake_minimum_required(VERSION 3.27)
project(vector-class CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(vector-class INTERFACE)

target_include_directories(vector-class INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

# options
option(VECTORCLASS_BUILD_TESTS "Enable test building" ON)

if (VECTORCLASS_BUILD_TESTS)
	add_subdirectory(tests)
	install(TARGETS vector-class-tests DESTINATION ${INSTALL_PATH})
endif()