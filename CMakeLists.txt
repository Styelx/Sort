cmake_minimum_required(VERSION 3.26)
project(Sort C)

set(CMAKE_C_STANDARD 23)

add_executable(Sort main.c
        sort.c
        sort.h)
