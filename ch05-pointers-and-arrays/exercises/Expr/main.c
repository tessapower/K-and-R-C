#include <stdio.h>

#include "expr.h"

// Exercise 5-10: Write the program expr, which evaluates a reverse Polish
//  expression from the command line, where each operator or operand is a
//  separate argument.

void printhelp(void);
const int minargs = 4;

int main(int argc, char **argv) {
  // We need at the minimum two operands and an operator for a valid
  // expression. First check for a minimum number of arguments and then check
  // for syntax validity later
  if (argc < minargs) {
    printhelp();

    return 1;
  }

  // Parse command line args
  while (--argc > 0) {
    if (!parse(*++argv)) {
      printf("error: unknown argument '%s'", *argv);

      return 1;
    }
  }
  
  double res;
  if (result(&res)) {
    printf("%g\n", res);
  } else {
    printf("error: invalid expression\n");

    return 1;
  }

  return 0;
}

void printhelp(void) {
  printf("Usage: expr 2 3 +\n");
  printf("  Evaluates basic arithmetic expressions in reverse "
    "Polish notation, a.k.a. Postfix notation\n");
  printf("  Passing the arguments \"1 2 - 4 5 + *\" is evaluated"
    " as (1 - 2) * (4 + 5)\n");
  printf("  Supported operators: + - * /");
}
