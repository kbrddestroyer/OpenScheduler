cmake_minimum_required(VERSION 3.16)
project(OpenScheduler LANGUAGES CXX)

if (POLICY CMP0140)
    cmake_policy(SET CMP0140 NEW)
endif()

include (cmake/build_utils.cmake)
add_all_subdirs()
