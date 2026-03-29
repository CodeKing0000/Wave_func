cmake_minimum_required(VERSION 3.23)
project(my_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED)

include(FetchContent)

set(BOOST_ENABLE_CMAKE ON)
set(BOOST_INCLUDE_LIBRARIES program_options filesystem regex)

FetchContent_Declare(
    Boost
    URL https://github.com/boostorg/boost/releases/download/boost-1.84.0/boost-1.84.0.tar.xz
)

FetchContent_MakeAvailable(Boost)

add_executable(${PROJECT_NAME} c.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    Boost::program_options
    Boost::filesystem
    Boost::regex
    Boost::test
)

add_executable(my_tests tests/test_main.cpp)
target_link_libraries(my_tests PRIVATE Boost::unit_test_framework)

enable_testing()
add_test(NAME my_tests COMMAND my_tests)