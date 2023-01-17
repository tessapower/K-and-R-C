#include <stdio.h>

#include "ioutils.h"

// Exercise 6-4: Write a program that prints the distinct words in its input
//  sorted into decreasing order of frequency of occurrence. Precede each word
//  by its count.

int main(int argc, char** argv) {
  const char* lines[4];
  lines[0] = "Lorem ipsum sit";
  lines[1] = " ipsum sit dolor ";
  lines[2] = "\n sit lorem ipsum sit";
  lines[3] = "sit dolor amet SIT DOLOR AMET";

  WordCount count = NULL;
  count = wordcount(lines, 4);

  printlist(count);

  freelist(count);

  return 0;
}
