cmake_minimum_required(VERSION 3.17)
project(Complex)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(googletest)

include_directories(src)
include_directories(googletest/googletest/include)

set(SOURCE_FILES src/complex.cpp)

add_executable(main main.cpp ${SOURCE_FILES} tests.cpp)
add_executable(tests tests.cpp ${SOURCE_FILES})

target_link_libraries(tests gtest)
