#include <stdio.h>
#include "calc.h"

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

bool push(double d) {
  if (sp < MAXVAL) {
    val[sp++] = d;

    return true;
  }

  printf("error: stack full, can't push %g\n", d);

  return false;
}

double pop(void) {
  if (sp > 0) return val[--sp];

  printf("error: stack empty\n");

  return 0.0;
}

void clear(void) {
  // We simulate clearing the stack by simply setting the stack position
  // back to the beginning and writing over any previous values.
  sp = 0;
}
