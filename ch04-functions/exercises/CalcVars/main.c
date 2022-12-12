#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

// Exercise 4-6: Add commands for handling variables. Add a variable for the
//  most recently printed value.
int main() {
  printf(" RPN Calculator!\n");
  printf("-----------------\n");
  printhelp();
  runcalc();

  return 0;
}