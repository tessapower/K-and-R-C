#include <stdio.h>
#include <stdbool.h>
#include "ioutils.h"

// Exercise 7-6: Write a program to compare two files, printing the first line
//  where they differ.

#define MAXLINE 1000

int main(int argc, char** argv) {
  if (argc != 3) {
    printf("Usage: %s <FILE1> <FILE2>\n", argv[0]);
    return 1;
  }

  FILE* f1;
  FILE* f2;
  if ((f1 = fopen(argv[1], "r")) == NULL) {
    printf("Error opening file: %s\n", argv[1]);
    return 1;
  }
  if ((f2 = fopen(argv[2], "r")) == NULL) {
    printf("Error opening file: %s\n", argv[2]);
    return 1;
  }

  // Read f1 and f2 line by line
  bool found = false;
  int i = 0;
  char l1[MAXLINE];
  char l2[MAXLINE];

  printf("\"%s\" vs. \"%s\": ", argv[1], argv[2]);
  while (getlinef(f1, l1, MAXLINE) != 0 && getlinef(f2, l2, MAXLINE) != 0) {
    // Compare the lines
    i++;
    found = strcmp(l1, l2) != 0;
    if (found) {
      // If they differ, print the line and break
      printf("files differ on line %i\n", i);
      prettyprintdiff(l1, l2);

      break;
    }
  }

  if (!found) {
    printf("files are identical\n");
  }

  // Close the files
  fclose(f1);
  fclose(f2);

  return 0;
}
