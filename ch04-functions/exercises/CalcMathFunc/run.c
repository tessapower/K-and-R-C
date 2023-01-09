#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"

int type;
double op2;
char s[MAXOP];
double vars[26];
int varidx = -1;
double last = 0.0;

void runcalc(void) {
  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      double d = atof(s);
      if (!push(d))
        printf("error: stack full, can't push %g\n", d);

      break;
    case ADD:                // "-12.5 3.25 +"
      push(pop() + pop());

      break;
    case SUB:                // "101 45.606 -"
      op2 = pop();
      push(pop() - op2);

      break;
    case MUL:                // "3.14159 2 *"
      push(pop() * pop());

      break;
    case DIV:                // "27 3.0 /"
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("! error: zero divisor\n");

      break;
    case MOD:                // "17 3 %"
      op2 = pop();
      if (op2 != 0.0) push(fmod(pop(), op2));
      else printf("error: zero divisor\n");

      break;
    case POW:                // "2 8 ^"
      op2 = pop();
      push(pow(pop(), op2));

      break;
    case EXP:                // "7 E"
      push(exp(pop()));

      break;
    case SIN:                // "0.5 ~"
      push(sin(pop()));

      break;
    case PRINT:              // "?"
      last = peek();
      printf("  = %.8g\n", last);

      break;
    case SWAP:               // "S"
      if (swaptop()) printf("swapped top two operands...\n");
      else printf("! error: not enough operands to swap\n");

      break;
    case DUPLICATE:          // "D"
      if (dup()) printf("pushed another %.8g...\n", peek());
      else printf("! error: could not push another %.8g\n", peek());

      break;
    case CLEAR:               // "C"
      clear();
      printf("cleared stack...\n");

      break;
    case '\r': case '\n':
      break;
    default:
      // Handle setting active variable
      if (type >= 'a' && type <= 'z') {
        varidx = type - 'a';
      } else {
        // If we reach this point, this command is unknown.
        printf("! error: unknown command %s\n", s);
      }

      break;
    }
  }
}

void printhelp(void) {
  // TODO Add note about unary and binary operators
  printf("Available operators: %c %c %c %c %c %c %c %c\n", ADD, SUB, DIV, MUL, MOD, POW, EXP, SIN);
  printf("Available commands:\n");
  printf("  %c: print last result\n", PRINT);
  printf("  %c: swap order of last two numbers\n", SWAP);
  printf("  %c: add the last number again\n", DUPLICATE);
  printf("  %c: clear the calculator\n", CLEAR);
}
