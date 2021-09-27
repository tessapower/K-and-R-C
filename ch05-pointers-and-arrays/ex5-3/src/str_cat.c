//
// Created by Tessa Power on 24/09/21.
//

#include "strCat.h"

// Write a pointer version of the function strcat that we showed in Chapter 2:
// strcat(s,t) copies the string t to the end of s.

// strCat: concatenate t to the end of s; s must be big enough
void str_cat(char *s, char* t) {
    int i = 0, j = 0;
    while (*s++ != '\0') // find end of s
        ;
    while ((*s++ = *t++) != '\0') // copy t
        ;
}
