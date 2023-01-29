#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Exercise 7-1: Write a program that converts upper case to lower case or
//  lower case to upper, depending on the name it is invoked with, as found
//  in arg[0].

int main(int argc, char** argv) {
  bool islower = true; // Set the default case

  if (strcasecmp("./upper", *argv) == 0) {
    islower = false;
  } else if (strcasecmp("./lower", *argv) != 0) {
    printf("Unknown program name: %s\n", *argv);
    printf("Usage: [lower | upper]\n");

    exit(-1);
  }

  int c = 0;
  while ((c = getchar()) != EOF) putchar(islower ? tolower(c) : toupper(c));

  return 0;
}
