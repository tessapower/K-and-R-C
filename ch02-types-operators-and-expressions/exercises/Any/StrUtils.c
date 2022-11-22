#include <stdio.h>
#include "StrUtils.h"

// Exercise 2-5: Write the function any(s1, s2), which returns the first
//  location in the string s1 where any character from the string s2 occurs, or
//  -1 if s1 contains no characters from s2.
int any(const char s1[], const char s2[]) {
  int j = 0;
  for (int i = 0; s2[i] != '\0'; ++i) {
    int idx = findFirst(s1, s2[i]);
    if (idx != -1) return idx;
  }

  return -1;
}

int findFirst(const char s[], const int c) {
  for (int i = 0; s[i] != '\0'; ++i) {
    if (s[i] == c) return i;
  }

  return -1;
}
