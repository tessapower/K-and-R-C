set(STR_CAT_HEADERS "${strCat_SOURCE_DIR}/include/str_cat.h")
add_library(str_cat STATIC str_cat.c ${STR_CAT_HEADERS})
target_include_directories(str_cat PUBLIC ../include)
