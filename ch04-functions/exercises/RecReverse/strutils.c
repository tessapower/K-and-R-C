#include <stdio.h>
#include <string.h>

#include "strutils.h"

// Exercise 4-13: Write a recursive version of the function reverse(s) which
//  reverses a string s in place.

void reverse(char s[]) { 
  static int i = 0;

  if (strlen(s) < 1) return;

  if (i == strlen(s) / 2) {
    i = 0;

    return;
  }

  swap(s, i, strlen(s) - i - 1);
  i++;
  reverse(s);
}

void swap(char s[], size_t i, size_t j) {
  char tmp = s[i];
  s[i] = s[j];
  s[j] = tmp;
}
