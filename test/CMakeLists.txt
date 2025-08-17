cmake_minimum_required(VERSION 3.25)
project(LiFM_DatatypesTests)

set(CMAKE_CXX_STANDARD 20)

add_executable(LiFM_DatatypesTests
    TestTemplate.cpp
)

target_link_libraries(LiFM_DatatypesTests PUBLIC
        GTest::gtest
        GTest::gtest_main
        LiFM_Timeline
)