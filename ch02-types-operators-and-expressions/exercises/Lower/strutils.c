#include "strutils.h"

// Exercise 2-10: Rewrite the function lower, which converts upper case letters
//  to lower case, with a conditional expression instead of if-else.
int lower(const int c) { return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c; }
