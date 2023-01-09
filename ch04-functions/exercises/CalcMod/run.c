#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"

int type;
double op2;
char s[MAXOP];

void runcalc() {
  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case ADD:
      push(pop() + pop());
      break;
    case SUB:
      op2 = pop();
      push(pop() - op2);
      break;
    case MUL:
      push(pop() * pop());
      break;
    case DIV:
      op2 = pop();
      if (op2 != 0.0) push(pop() / op2);
      else printf("error: zero divisor\n");
      break;
    case MOD:
      op2 = pop();
      if (op2 != 0.0) push(fmod(pop(), op2));
      else printf("error: zero divisor\n");
      break;
    case '\r':
      break;
    case '\n':
      printf("= %.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
}

