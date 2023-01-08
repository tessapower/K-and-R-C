#include <stdio.h>
#include <string.h>

#include "strutils.h"

// Exercise 2-4: Write an alternate version of squeeze(s1, s2) that deletes
//  each character in s1 that matches any character in the string s2.

void squeeze(char s[], const char todelete[]) {
  int j = 0;
  for (int i = 0; s[i] != '\0'; ++i) {
    if (!contains(todelete, s[i])) {
      s[j++] = s[i];
    }
  }

  s[j] = '\0';
}

bool contains(const char s[], const int c) {
  for (int i = 0; s[i] != '\0'; ++i) {
    if (s[i] == c) return true;
  }

  return false;
}
