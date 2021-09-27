cmake_minimum_required(VERSION 3.20)
project(examples C)

set(CMAKE_C_STANDARD 11)

add_executable(echo echo.c)
add_executable(find find.c)
add_executable(find_with_params find_with_params.c)
add_executable(sort sort.c)
add_executable(strcpy strcpy.c)
