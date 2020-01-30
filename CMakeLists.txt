cmake_minimum_required(VERSION 2.6)

# Locate GTest
#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(sections-test src/main.cpp)

#target_compile_options(
#  runTests
#  PUBLIC "-O0"
#)

#target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

#add_custom_command(TARGET runTests POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E rename runTests.exe runTests2.exe
#)
