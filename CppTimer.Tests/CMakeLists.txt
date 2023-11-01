#
# This is a CMake project file for unit tests of CPP based versatile Timer with callback support.
#
cmake_minimum_required(VERSION 3.17.0)

project(CppTimerTests VERSION 0.0.0.1 LANGUAGES CXX)

################################################################
# Configurations
################################################################
include(${CMAKE_CURRENT_SOURCE_DIR}/../Build/DefaultCmakeSettings.cmake)

################################################################################
# VARIABLES
################################################################################
set(CPP_TIMER_TEST_TARGET_NAME ${PROJECT_NAME})

set(CPP_TIMER_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../Src")
set(CPP_TIMER_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../Include")
set(CPP_TIMER_TEST_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Src")

################################################################################
# Dependencies
################################################################################
find_package(FrameworkGtest)

################################################################################
# Targets
################################################################################
add_executable(${CPP_TIMER_TEST_TARGET_NAME})
add_subdirectory("${CPP_TIMER_TEST_SOURCE_DIR}")

target_include_directories(${CPP_TIMER_TEST_TARGET_NAME}
    PRIVATE
        "${CPP_TIMER_TEST_SOURCE_DIR}"
        "${CPP_TIMER_INCLUDE_DIR}"
)

target_link_libraries(${CPP_TIMER_TEST_TARGET_NAME}
    PRIVATE
        framework::gtest_suite
)

enable_testing()

gtest_discover_tests(${CPP_TIMER_TEST_TARGET_NAME})