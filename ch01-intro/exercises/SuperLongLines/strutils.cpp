#include <stdio.h>
#include "strutils.h"

// Reads a line into s, returns the length
int getline(char s[], const int lim, int (*getc)()) {
  int c = 0;
  // Declare i outside of loop so we can return the length
  int len = 0;
  int i = 0;
  while ((c = getc()) != EOF && c != '\n' && c != '\0') {
    if (i < lim - 1) {
      s[i++] = c;
    };

    ++len;
  }

  // Handle end of line
  if (c == '\n') {
    if (i > 0 && s[i - 1] == '\r') {
      --i;
      --len;
    }
    s[i] = c;
    ++i;
    ++len;
  }
  s[i] = '\0';

  return ++len;
}
