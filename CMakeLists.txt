cmake_minimum_required(VERSION 3.0)
project(ENIGMA)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Include Google Test in the build process
add_subdirectory(extern/googletest)

# Ensure your project can find the Google Test headers
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_library(MyLibrary src/simple_lib.cpp)


add_executable(ENIGMA src/main.cpp src/Rotor.cpp src/Reflector.cpp)

target_link_libraries(ENIGMA sfml-graphics sfml-audio)


# Add the tests
add_executable(runSimpleLibTest test/test_simple_lib.cpp src/simple_lib.cpp)
target_link_libraries(runSimpleLibTest gtest gtest_main)
