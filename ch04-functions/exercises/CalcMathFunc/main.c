#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

// Exercise 4-5: Add access to library functions like sin, exp, and pow from
//   the math.h header.
int main() {
  printf(" RPN Calculator!\n");
  printf("-----------------\n");
  printhelp();
  runcalc();

  return 0;
}
