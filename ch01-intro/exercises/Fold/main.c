#include <stdio.h>
#include "strutils.h"

#define FOLD_LIMIT 79

// Exercise 1-22: Write a program to "fold" long input lines into two or more
//  shorter lines after the last non-blank character that occurs before the nth
//  column of input. Make sure your program does something intelligent with
//  very long lines, and if there are no blanks or tabs before the specified
//  column.
int main() {
  int linelength;
  char line[MAX_LINE];

  while ((linelength = getline(line)) > 0) {
    if (line[0] != '\n') {
      fold(line, FOLD_LIMIT);
      printf("%s", line);
    }
  }

  return 0;
}
