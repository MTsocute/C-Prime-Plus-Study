cmake_minimum_required(VERSION 3.23)
project(C_Learning)

set(CMAKE_CXX_STANDARD 14)

add_executable(plist
        Chapter17/list.cpp
        Chapter17/main_list.cpp
        )

target_include_directories(plist PUBLIC Chapter17)