#include <stdio.h>

#include "ioutils.h"

// Exercise 6-3: Write a cross-referencer that prints a list of all words in a
//  document, and, for each word, a list of the line numbers on which it
//  occurs. Remove noise words like "the", "and", and so on.

int main(int argc, char** argv) {
  const char* lines[4];
  lines[0] = "Lorem ipsum sit";
  lines[1] = " ipsum sit dolor ";
  lines[2] = "\n sit";
  lines[3] = "sit dolor amet";

  WordTree root = NULL;
  root = wordtree(lines, 4);

  printwordtree(root);

  freewordtree(root);

  return 0;
}