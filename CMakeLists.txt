cmake_minimum_required(VERSION 3.23)
project(C_Learning)

set(CMAKE_CXX_STANDARD 14)

# Search All .cpp file and name them SOURCE
# file(GLOB SOURCE 'Detail/*.cpp')
#add_executable(C_Learning main.cpp ${SOURCE})

add_executable(C_Learning
        main.cpp
        Chapter16/条件编译/ifdef.cpp
        Chapter16/条件编译/if_条件定义.cpp
)

#[[
    With below function[target_include...()],
    we don't have to code like this:
        add_executable(C_Learning main.cpp \Homework\Chapter_2.h)
]]

add_executable(RECT_TO_POL Chapter16/直角坐标转极坐标.cpp)
add_executable(assert Chapter16/断言库.cpp)
add_executable(arr_CP Chapter16/数组的拷贝.cpp)
add_executable(variable_para Chapter16/可变参数.cpp)

target_include_directories(C_Learning PRIVATE
        Homework
        Chapter10
        Chapter11
        Chapter12
        Chapter13
        Chapter14
        Chapter15
        Chapter16
        )  # We can use this to avoid type head file in add_exe...()
