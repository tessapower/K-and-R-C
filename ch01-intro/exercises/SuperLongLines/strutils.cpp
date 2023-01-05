#include <stdio.h>
#include "strutils.h"

// Reads a line into s, returns the length
int getline(char s[], const int lim, int (*getc)()) {
  int c = 0;
  // Declare i outside of loop so we can return the length
  int len = 0;
  int i = 0;
  while ((c = getc()) != EOF && c != '\n' && c != '\0') {
    if (i < lim - 2) {
      s[i++] = c;
    };

    ++len;
  }

  // Handle end of line
  if (c == '\n') {
    if (i > 0 && s[i - 1] == '\r') { // Remove carriage returns
      --i;
      --len;
    }
    // Add the newline character
    s[i] = c;
    ++i;
    ++len;
  }

  // Add terminating character
  s[i] = '\0';

  return ++len;
}

void copy(char dest[], char source[]) {
  int i = 0;
  while ((dest[i] = source[i]) != '\0') i++;
}
