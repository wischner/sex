cmake_minimum_required(VERSION 3.10)

# Project Name
project(HaikuSexProject LANGUAGES C CXX)

# Set C++ standard globally
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set default build type to Debug if none is specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Output build type info
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# Add the src folder to the build
add_subdirectory(src)