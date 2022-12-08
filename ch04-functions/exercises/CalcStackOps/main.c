#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

// Exercise 4-4: Add commands to print the top element of the stack without
//  popping, to duplicate it, and do swap the top two elements. Add a command
//  to clear the stack.
int main() {
  printf(" RPN Calculator!\n");
  printf("-----------------\n");
  printhelp();
  runcalc();

  return 0;
}
