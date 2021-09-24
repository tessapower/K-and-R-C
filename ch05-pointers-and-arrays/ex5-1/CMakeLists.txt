cmake_minimum_required(VERSION 3.20)
project(getint C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(getint
        bin/main.c
        include/getint.h
        src/getint.c)
