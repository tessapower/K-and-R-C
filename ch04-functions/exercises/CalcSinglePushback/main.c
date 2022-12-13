#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

// Exercise 4-8: Suppose there will never be more than one character of
//   pushback. Modify getch and ungetch accordingly.
int main() {
  printf(" RPN Calculator!\n");
  printf("-----------------\n");
  printhelp();
  runcalc();

  return 0;
}