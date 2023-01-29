#include <stdio.h>
#include <ctype.h>
#include "calc.h"

void skipws();
bool isdecpoint(const int c);
bool isoperator(const int c);
bool isnum(const int c);
bool isnegativenum(const int c);
bool isdecnum(const int c);
bool iscommand(const int c);
bool isvalidvarname(const int c);

/**
 * @brief Get next operator or numeric operand
*/
int getop(char s[]) {
  skipws();

  // Get the first character from stdin
  int i = 0;
  int c = getch();
  s[i++] = c;
  s[i] = '\0';

  if (c == VAR_ACCESS && isvalidvarname(peekch())) s[0] = getch();

  if (!isnum(c)) return c;

  // Integer
  while (isdigit(peekch())) {
    c = getch();
    s[i++] = c;
  }

  // Fraction
  if (isdecpoint(peekch())) {
    // Add the decimal point
    c = getch();
    s[i++] = c;
    // Collect fractional part
    while (isdigit(peekch())) {
      c = getch();
      s[i++] = c;
    }
  }

  s[i] = '\0';

  return NUMBER;
}

void skipws() {
  while (isspace(peekch())) getch();
}

bool isdecpoint(const int c) {
  return c == '.';
}

bool isoperator(const int c) {
  return c == ADD || c == SUB || c == MUL || c == DIV || c == MOD;
}

bool isnum(const int c) {
  return isdigit(c) || isnegativenum(c) || isdecnum(c);
}

bool isnegativenum(const int c) {
  const int next = peekch();
  return c == '-' && (isdigit(next) || isdecnum(next));
}

bool isdecnum(const int c) {
  const int next = peekch();
  return (isdecpoint(c) && isdigit(next)) || (isdigit(c) && isdecpoint(next));
}

bool iscommand(const int c) {
  return c == PRINT || c == SWAP || c == DUPLICATE || c == CLEAR;
}

bool isvalidvarname(const int c) {
  return (c >= 'a' && c <= 'z') || c == VAR_ACCESS;
}
