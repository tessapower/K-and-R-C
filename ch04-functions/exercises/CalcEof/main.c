#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

// Exercise 4-9: Our getch and ungetch do not handle a pushed-back EOF
//  correctly. Decide what their properties ought to be if an EOF is pushed
//  back, then implement your design.
int main() {
  printf(" RPN Calculator!\n");
  printf("-----------------\n");
  printhelp();
  runcalc();

  return 0;
}