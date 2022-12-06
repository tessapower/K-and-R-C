#include "strutils.h"

#include <stdio.h>

// Exercise 4-1: Write the function strrindex(s, t) which returns the position
//  of the rightmost occurence of t in s, or -1 if there is none.
int strrindex(const char s[], const char t[]) {
  int last = -1;
  for (int i = 0; s[i] != '\0'; ++i) {
    int k = 0;
    for (int j = i; t[k] != '\0' && s[j] == t[k]; ++j, ++k)
      ;
   
    if (k > 0 && t[k] == '\0') last = i;
  }

  return last;
}
