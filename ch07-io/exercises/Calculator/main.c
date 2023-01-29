#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

// Exercise 7-5: Rewrite the postfix calculator of Chapter 4 to use scanf and/or
//  sscanf to do the input and number conversion.

// To run this on Ubuntu, link against the math library:
//  gcc -o calc main.c run.c getop.c stack.c -lm && ./calc

int main() {
  printf(" RPN Calculator!\n");
  printf("-----------------\n");
  printhelp();
  runcalc();

  return 0;
}
