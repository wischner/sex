cmake_minimum_required(VERSION 3.10)

# Project Name
project(HaikuSexProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Target system (Haiku)
set(CMAKE_SYSTEM_NAME Haiku)

# Set Debug Build Type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Define source files
set(SRC_FILES src/main.cpp)

# Add the executable
add_executable(HaikuSex ${SRC_FILES})

# Find Haiku system include directories and libraries
find_path(HAIKU_INCLUDE_DIR NAMES app/Application.h PATHS /boot/system/develop/headers/be)
find_library(HAIKU_LIB_BE NAMES be PATHS /boot/system/develop/lib)

# Include Haiku headers
target_include_directories(HaikuSex PRIVATE ${HAIKU_INCLUDE_DIR})

# Link against Haiku's BeAPI
target_link_libraries(HaikuSex PRIVATE ${HAIKU_LIB_BE})