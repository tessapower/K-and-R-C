#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"

int type;
double op2;
char s[MAXOP];

void runcalc(void) {
  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      double d = atof(s);
      bool pushed = push(d);

      if (!pushed) printf("error: stack full, can't push %g\n", d);
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
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("! error: zero divisor\n");
      break;
    case MOD:
      op2 = pop();
      if (op2 != 0.0) push(fmod(pop(), op2));
      else printf("error: zero divisor\n");
      break;
    case PRINT:
      printf("  = %.8g\n", peek());
      break;
    case SWAP:
      bool swapped = swaptop();

      if (swapped) printf("swapped top two operands...\n");
      else printf("! error: not enough operands to swap\n");
      break;
    case DUPLICATE:
      bool added = dup();

      if (added) printf("pushed another %.8g...\n", peek());
      else printf("! error: could not push another %.8g\n", peek());
      break;
    case CLEAR:
      clear();
      printf("cleared stack...\n");
      break;
    case '\r': case '\n':
      break;
    default:
      printf("! error: unknown command %s\n", s);
      break;
    }
  }
}

void printhelp(void) {
  printf("Available operators: %c %c %c %c %c\n", ADD, SUB, DIV, MUL, MOD);
  printf("Available commands:\n");
  printf("  %c: print last result\n", PRINT);
  printf("  %c: swap order of last two numbers\n", SWAP);
  printf("  %c: add the last number again\n", DUPLICATE);
  printf("  %c: clear the calculator\n", CLEAR);
}
