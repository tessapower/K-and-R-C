#include "expr.h"

#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool parse(const char *arg) {
  bool success = false;

  enum Type t = type(arg);
  switch (t) {
    case NUMBER: {
      success = push(atof(arg));

      break;
    }
    case OPERATOR: {
      switch (*arg) {
        case ADD: {
          if (size() >= 2) success = push(pop() + pop());
          else success = false;

          break;
        }
        case SUB: {
          if (size() >= 2) {
            double op2 = pop();
            success = push(pop() - op2);
          } else {
            success = false;
          }

          break;
        }
        case MUL: {
          if (size() >= 2) success = push(pop() * pop());
          else success = false;

          break;
        }
        case DIV: {
          if (size() >= 2) {
            double op2 = pop();
            if (op2 != 0) success = push(pop() / op2);
            else success = false;
          } else {
            success = false;
          }

          break;
        }
      }

      break;
    }
    case UNKNOWN: success = false;
  }

  return success;
}

enum Type type(const char* arg) {
  if (isoperator(arg)) return OPERATOR;
  if (isdigit(*arg) || isnegnum(arg)) return NUMBER;
  
  return UNKNOWN;
}

bool isoperator(const char* arg) {
  return strcmp(arg, "+") == 0 || strcmp(arg, "-") == 0
    || strcmp(arg, "*") == 0 || strcmp(arg, "/") == 0;
}

bool isnegnum(const char *s) {
  return atof(s) < 0.0;
}

bool result(double *res) {
  if (isempty()) {
    // Either nothing has been parsed yet or we have only seen operators
    *res = 0.0;

    return false;
  }

  // Get the value at the top of the stack.
  *res = peek();

  if (size() != 1) {
    // If we have more than one thing on the stack then we have not seen enough
    // operators yet, so the expression so far is not valid syntatically
    return false;
  }

  return true;
}

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

bool push(const double operand) {
  if (size() < MAXVAL) {
    val[sp++] = operand;

    return true;
  }

  return false;
}

double pop(void) {
  if (!isempty()) return val[--sp];

  return 0.0;
}

double peek(void) {
  if (!isempty()) return val[sp - 1];

  return 0.0;
}

int size(void) {
  return sp;
}

bool isempty(void) {
  return sp == 0;
}

void clear(void) {
  sp = 0;
}
