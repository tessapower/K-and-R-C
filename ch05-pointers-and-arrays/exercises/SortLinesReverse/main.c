#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "strutils.h"
#include "sort.h"
#include "compare.h"

// Exercise 5-14: Modify the sort program to handle a -r flag, which indicates
//  sorting in reverse (decreasing) order. Be sure that -r works with -n.

#define MAXLINES 5000
char *lineptr[5000];

int main(int argc, char** argv) {
  bool numeric = false;

  if (argc > 1 && strcmp(argv[1], "-n") == 0) {
    numeric = true;
  }
  
  int nlines = 0;
  if ((nlines = readlines(lineptr, MAXLINES, getchar)) == -1) {
    printf("input too big to sort\n");

    return 1;
  }

  // Sort the lines either numerically or lexicographically
  qsort((void **) lineptr, 0, nlines - 1,
    (int (*)(void *, void *))(numeric ? numcmp : strcmp));

  // write to stdout
  writelines(lineptr, nlines);

  return 0;
}
