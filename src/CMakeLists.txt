cmake_minimum_required(VERSION 3.31)
project(LiFM_Datatypes)

set(CMAKE_CXX_STANDARD 23)

add_library(LiFM_Datatypes
        Club.cpp
        League.cpp
        Match.cpp
        Dataholder.hpp
        LeagueTable.cpp
)

target_link_libraries(LiFM_Datatypes PUBLIC Utility LiFM_Timeline)
