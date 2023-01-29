#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
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
      case NUMBER: {
        double d = atof(s);
        if (!push(d))
          printf("error: stack full, can't push %g\n", d);

        break;
      }
      case ADD: {               // "-12.5 3.25 +"
        push(pop() + pop());

        break;
      }
      case SUB: {               // "101 45.606 -"
        op2 = pop();
        push(pop() - op2);

        break;
      }
      case MUL: {               // "3.14159 2 *"
        push(pop() * pop());

        break;
      }
      case DIV: {               // "27 3.0 /"
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("! error: zero divisor\n");

        break;
      }
      case MOD: {               // "17 3 %"
        op2 = pop();
        push((int)pop() % (int)op2);

        break;
      }
      case POW: {               // "2 8 ^"
        op2 = pop();
        push(pow(pop(), op2));

        break;
      }
      case EXP: {               // "7 E"
        push(exp(pop()));

        break;
      }
      case SIN: {               // "0.5 ~"
        push(sin(pop()));

        break;
      }
      case VAR_ASSIGN: {        // "e 20 ="
        if (varidx == -1) {
          printf("error: no variable was specified\n");
        } else {
          vars[varidx] = pop();
          // unset active variable
          varidx = -1;
        }

        break;
      }
      case VAR_ACCESS: {
        // Get the variable name
        int var = s[0];
        // Push the value onto the stack if the variable name is valid
        if (var >= 'a' && var <= 'z') {
          int idx = var - 'a';
          double v = vars[idx];
          if (!push(v))
            printf("error: stack full, can't push %g\n", v);
        } else if (var == VAR_ACCESS) {
          if (!push(last))
            printf("error: stack full, can't push %g\n", last);
        }

        break;
      }
      case PRINT: {             // "?"
        last = peek();
        printf("  = %.8g\n", last);

        break;
      }
      case SWAP: {              // "S"
        if (swaptop()) printf("swapped top two operands...\n");
        else printf("! error: not enough operands to swap\n");

        break;
      }
      case DUPLICATE: {        // "D"
        if (dup()) printf("pushed another %.8g...\n", peek());
        else printf("! error: could not push another %.8g\n", peek());

        break;
      }
      case CLEAR: {             // "C"
        clear();
        printf("cleared stack...\n");

        break;
      }
      case '\r': case '\n': case EOF: break;
      default: {
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
}

void printhelp(void) {
  printf("Available operators:\n");
  printf("  %c %c %c %c: add, subtract, divide, or multiply two numbers\n",
    ADD, SUB, DIV, MUL);
  printf("  %c: mod two integer numbers\n", MOD);
  printf("  %c: x to the nth power\n", POW);
  printf("  %c: e to the nth power\n", EXP);
  printf("  %c: sine of x in radians\n\n", SIN);

  printf("Available variables: a-z\n");
  printf("Assign to variables with %c, e.g. a 10 %c\n",
    VAR_ASSIGN, VAR_ASSIGN);
  printf("Access their values with %c, e.g. a %ca 20 +\n",
    VAR_ACCESS, VAR_ACCESS);
  printf("Access the last printed value with %c%c\n\n",
    VAR_ACCESS, VAR_ACCESS);

  printf("Available commands:\n");
  printf("  %c: print last result\n", PRINT);
  printf("  %c: swap order of last two numbers\n", SWAP);
  printf("  %c: add the last number again\n", DUPLICATE);
  printf("  %c: clear the calculator\n", CLEAR);
}
