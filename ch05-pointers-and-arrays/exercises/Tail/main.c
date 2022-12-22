#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ioutils.h"

void printhelp(void);

int main(int argc, char** argv) {
  if (argc > 3) {
    printhelp();

    return 1;
  }

  int nlines = DEFAULT;
  
  if (argc == 3) {
    // match -n argument, anything else is an unknown argument
    if (strcmp(argv[1], "-n") == 0) {
      int n = atoi(argv[2]);

      // Handle being given silly values
      if (n < 0) {
        nlines = n;
      } else if (n > MAXLINES) {
        nlines = MAXLINES;
      }
    } else {
      printf("Unknown argument '%s'", argv[1]);

      return 1;
    }
  }

  printf("> ");
  char** lines = NULL;
  int nread = readlines(&lines, nlines, getchar);

  if (lines != NULL) {
    printf("\nOutput:\n");
    for (int i = 0; i < nread; ++i) {
      if (strlen(lines[i]) > 0) {
        printf("%s", lines[i]);
      }
      
      free(lines[i]);
    }
  }

  free(lines);

  return 0;
}

void printhelp(void) {
  // print usage
  printf("Usage: tail [-n]");
  printf("Prints the last n lines of the input.");
}
