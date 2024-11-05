cmake_minimum_required(VERSION 3.30)
project(Todo_list)

set(CMAKE_CXX_STANDARD 14)

add_executable(Todo_list main.cpp
        Task.cpp
        Task.h
        DateTime.h)
