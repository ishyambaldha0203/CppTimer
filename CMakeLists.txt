#
# This is a CMake project file for CPP based versatile Timer with callback support.
#
cmake_minimum_required(VERSION 3.19.0)

project(CppTimer VERSION 0.0.0.1 LANGUAGES CXX)

################################################################
# Configurations
################################################################
include(${CMAKE_CURRENT_SOURCE_DIR}/Build/DefaultCmakeSettings.cmake)

set(CMAKE_BUILD_TYPE Debug)

################################################################
# VARIABLES
################################################################
set(CPP_TIMER_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Include")
set(CPP_TIMER_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Src")
set(CPP_TIMER_TARGET_NAME timer_demo_application)

################################################################
# DEPENDENCIES
################################################################
find_package(Threads REQUIRED)

################################################################
# TARGESTS
################################################################

# Add source to this project's executable.
add_executable(${CPP_TIMER_TARGET_NAME})
add_subdirectory(${CPP_TIMER_SOURCE_DIR})

################################################################
# INCLUDES
################################################################

target_include_directories(${CPP_TIMER_TARGET_NAME} PRIVATE
    ${CPP_TIMER_INCLUDE_DIR}
)

target_link_libraries(${CPP_TIMER_TARGET_NAME} PRIVATE
    Threads::Threads
)
