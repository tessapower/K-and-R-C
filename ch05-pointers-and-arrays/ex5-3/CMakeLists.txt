cmake_minimum_required(VERSION 3.20)
project(strCat C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(CMAKE_CXX_EXTENSIONS OFF)
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    include(CTest)
endif()

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    add_subdirectory(tests)
endif()

add_library(str_cat include/str_cat.h src/str_cat.c)
