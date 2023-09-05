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


add_executable(ENIGMA src/main.cpp src/Rotor.cpp src/Reflector.cpp src/Enigma.cpp src/Plugboard.cpp)

target_link_libraries(ENIGMA sfml-graphics sfml-audio)


# Add the tests
add_executable(runSimpleLibTest test/test_simple_lib.cpp src/simple_lib.cpp)
target_link_libraries(runSimpleLibTest gtest gtest_main)
# Reflector test
add_executable(runReflectorTest test/test_Reflector.cpp src/Reflector.cpp)
target_link_libraries(runReflectorTest gtest gtest_main)
# Rotor test
add_executable(runRotorTest test/test_Rotor.cpp src/Rotor.cpp)
target_link_libraries(runRotorTest gtest gtest_main)
# Enigma test
add_executable(runEnigmaTest test/test_Enigma.cpp src/Enigma.cpp src/Rotor.cpp src/Reflector src/Plugboard.cpp)
target_link_libraries(runEnigmaTest gtest gtest_main)
# Plugboard test
add_executable(runPlugboardTest test/test_Plugboard.cpp src/Plugboard.cpp)
target_link_libraries(runPlugboardTest gtest gtest_main)