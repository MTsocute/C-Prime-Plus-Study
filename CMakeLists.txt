cmake_minimum_required(VERSION 3.23)
project(C_Learning)

set(CMAKE_CXX_STANDARD 14)

# Search All .cpp file and name them SOURCE
# file(GLOB SOURCE 'Detail/*.cpp')
#add_executable(C_Learning main.cpp ${SOURCE})

add_executable(C_Learning main.cpp)

#[[
    With below function[target_include...()],
    we don't have to code like this:
        add_executable(C_Learning main.cpp \Homework\Chapter_2.h)
]]
target_include_directories(C_Learning PRIVATE Homework)  # We can use this to avoid type head file in add_exe...()
target_include_directories(C_Learning PRIVATE Chapter4)
