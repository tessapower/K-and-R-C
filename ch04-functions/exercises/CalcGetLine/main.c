#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

// Exercise 4-10: An alternate organization uses getline to read an entire
//  input line; this makes getch and ungetch unnecessary. Revice the calculator
//  to use this approach.
int main() {
  printf(" RPN Calculator!\n");
  printf("-----------------\n");
  printhelp();
  runcalc();

  return 0;
}