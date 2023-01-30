#include "strutils.h"

// Exercise 7-9: Functions like isupper can be implemented to save space or to
//  save time. Explore both possibilities.

// This implementation saves time by using a macro instead of a costly function
// call. The downside to using this macro is that evaluated expressions passed
// as arguments are evaluated multiple times. This could cause unexpected
// results if the argument is an expression with side effects.
#define ISUPPER(c) ((c) >= 'A' && (c) <= 'Z')

// This implementation saves space by using a function instead of a macro, which
// is only defined in one place. The macro will be expanded out and inserted
// wherever it is used, which can cause the program to be larger. The downside
// to using this function is that it is a function call, which is more costly
// than a macro.
int isupper(const char c) {
  return c >= 'A' && c <= 'Z';
}
