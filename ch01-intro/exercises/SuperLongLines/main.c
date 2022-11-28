#include <stdio.h>
#include "strutils.h"

#define MAX_LINE 1000 // Maximum input line size

// Exercise 1-16: Revise the main routine of the longest line program so it
//  will correctly print the length of arbitrarily long input lines, and as
//  much as possible of the text.
int main() {
  int len;
  char l[MAX_LINE];

  while ((len = getline(l, MAX_LINE, getchar)) > 0) {
    printf("%d\n", len);
    printf("%s", l);
  }

  return 0;
}
