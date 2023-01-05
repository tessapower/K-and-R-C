#include <stdio.h>
#include "strutils.h"

#define MAX_LINE 1000 // Maximum input line size

// Exercise 1-16: Revise the main routine of the longest line program so it
//  will correctly print the length of arbitrarily long input lines, and as
//  much as possible of the text.
int main() {
  char l[MAX_LINE];
  char longest[MAX_LINE];
  int max = 0;
  int len;

  while ((len = getline(l, MAX_LINE, getchar)) > 0 && l[0] != '\n') {
    printf("%d\n", len);
    printf("%s", l);
    if (len > max) {
      max = len;
      copy(longest, l);
    }
  }

  // print longest line if there were any
  if (max > 0) printf("longest: %s", longest);

  return 0;
}
