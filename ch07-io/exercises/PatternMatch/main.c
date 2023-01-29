#include <stdio.h>
#include <string.h>
#include "ioutils.h"

// Exercise 7-7: Modify the pattern finding program of Chapter 5 to take its
//  input from a set of named files or, if no files are named as arguments, from
//  the standard input. Should the file name be printed when a matching line is
//  found?

#define MAXLINE 1000

void printhelp(char* progname);

int main(int argc, char** argv) {
  if (argc < 2) {
    printhelp(argv[0]);

    return 1;
  }

  int c;
  int except = 0;
  int number = 0;
  int found = 0;
  while (--argc > 0 && (*++argv)[0] == '-') {
    while (c = *++argv[0]) {
      switch (c) {
        case 'x':
          except = 1;
          break;
        case 'n':
          number = 1;
          break;
        default:
          printf("%s: illegal option %c\n", argv[0], c);
          printhelp(argv[0]);

          argc = 0;
          found = -1;
          break;
      }
    }
  }

  // Ensure pattern is present
  if (argc < 1) {
    printhelp(argv[0]);

    return 1;
  }

  char line[MAXLINE];
  long lineno = 0;
  // If no files, read from the standard input
  if (argc == 1) {
    printf("Reading from stdin...\n");
    while (getlinef(stdin, line, MAXLINE) > 0) {
      lineno++;
      if ((strstr(line, *argv) != NULL) != except) {
        // Print the line number
        if (number) {
          printf("Line %ld: ", lineno);
        }

        // Print the line
        printf("%s", line);
        int len = strlen(line);
        if (len > 0 && line[len - 1] != '\n') {
          printf("\n");
        }

        found++;
      }
    }
  } else {
    // Work through each file
    char* pattern = *argv++;
    FILE* file;
    while (--argc > 0) {
      if ((file = fopen(*argv, "r")) == NULL) {
        printf("Error opening file: %s\n", *argv);
        return 1;
      }

      while (getlinef(file, line, MAXLINE) > 0) {
        lineno++;
        if ((strstr(line, pattern) != NULL) != except) {
          // Print file name if a matching line is found
          printf("\"%s\", ", *argv);

          // Print the line number
          if (number) {
            printf("line %ld: ", lineno);
          }

          // Print the line
          printf("%s", line);
        int len = strlen(line);
        if (len > 0 && line[len - 1] != '\n') {
          printf("\n");
        }

          found++;
        }
      }

      fclose(file);
      argv++;
    }
  }

  return found;
}

void printhelp(char* progname) {
  printf("Usage: %s [OPTION]... PATTERN [FILE]...\n", progname);
  printf("  -x: print lines that do not match the pattern\n");
  printf("  -n: print line numbers\n");
}
