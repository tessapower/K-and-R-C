#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

// Exercise 4-7: Write a routine ungets(s) that will push back an entire string
//  onto the input. Should ungets know about buf and bufp, or should it just
//  use ungetch?
int main() {
  printf(" RPN Calculator!\n");
  printf("-----------------\n");
  printhelp();
  runcalc();

  return 0;
}