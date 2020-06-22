cmake_minimum_required(VERSION 3.16)
project(Serial_Communication)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Boost)

if (NOT boost_FOUND)

    set(Boost_INCLUDE_DIR "C:/boost")
    set(Boost_LIBRARY_DIRS "C:/boost/stage/lib")
    set(Boost_LIBRARIES "")

endif()

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIRS})

add_executable(Serial_Communication main.cpp main.hpp)
target_link_libraries(Serial_Communication ${Boost_LIBRARIES})

# Utilities

set(CMAKE_DIR "C:/Cmake")
find_program(CMAKE_EXECUTABLE NAMES cmake HINTS ${cmake_dir} ENV CMAKE_DIR PATH_SUFFIXES bin)

# Build

set_property(TARGET Serial_Communication PROPERTY CXX_STANDARD 17)

# Install

install(TARGETS Serial_Communication DESTINATION ${PROJECT_SOURCE_DIR}/bin)

