#include "strcat.h"

// Exercise 5-3: Write a pointer version of the function strcat that we showed
//  in chapter 2: strcat(s, t) copies the string t onto the end of s.

void strconcat(char *s, char *t) {
  // Find end of s
  while (*s != '\0')
    s++;

  // Copy t
  while (*s++ = *t++)
    ;
}
