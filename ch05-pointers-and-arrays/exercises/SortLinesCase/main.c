#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "strutils.h"
#include "sort.h"

// Exercise 5-14: Modify the sort program to handle a -r flag, which indicates
//  sorting in reverse (decreasing) order. Be sure that -r works with -n.

#define MAXLINES 5000
char *lineptr[5000];

void printhelp(void);

int main(int argc, char** argv) {
  int options = 0x0000;

  while (--argc && (*++argv)[0] == '-') {
    int c = 0;
    while (c = *++argv[0]) {
      switch (c) {
      case 'r':
        options |= REVERSE;
        break;
      case 'n':
        options |= NUMERIC;
        break;
      case 'f':
        options |= CASE_INSENSITIVE;
        break;
      default:
        printf("unknown argument %c\n", c);
        printhelp();
        
        return 1;
      }
    }
  }
  
  int nlines = 0;
  if ((nlines = readlines(lineptr, MAXLINES, getchar)) == -1) {
    printf("input too big to sort\n");

    return 1;
  }

  // Sort the lines of input
  sort((void **) lineptr, nlines, options);

  // Write lines to stdout
  writelines(lineptr, nlines);

  return 0;
}

void printhelp(void) {
  printf("Usage: sort [-r] [-n]\n");
  printf("  -r: sort in reverse order\n");
  printf("  -n: sort numerically\n");
}
