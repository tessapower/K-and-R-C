//
// Created by Tessa Power on 24/09/21.
//

#include "str_cat.h"

// Write a pointer version of the function strcat that we showed in Chapter 2:
// strcat(s,t) copies the string t to the end of s.

// str_cat: concatenate t to the end of s; s must be big enough
void str_cat(char *s, char* t) {
    if (s != '\0' && t != '\0') {
        while (*++s != '\0') // find end of s
            ;
        while ((*s++ = *t++) != '\0') // copy t
            ;
    }
}
