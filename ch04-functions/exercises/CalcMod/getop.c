#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "calc.h"

void skipws();
bool isdecpoint(int c);
bool isoperator(int c);
bool isnegativenum(int c);

/**
 * @brief Get next operator or numeric operand
*/
int getop(char s[]) {
  skipws();

  // Get the first character from stdin
  int c = getch();
  int i = 0;
  s[i++] = c;
  s[i] = '\0';

  if (isoperator(c) && !isnegativenum(c)) return c;

  // If we reach this point, we're dealing with a numeric operand
  // Collect integer part
  c = getch();
  if (isdigit(c)) {
    s[i++] = c;
    while (isdigit(c = getch())) s[i++] = c;
  }

  // Collect fraction part
  if (isdecpoint(c)) {
    s[i++] = c;
    while (isdigit(c = getch())) s[i++] = c;
  }

  s[i] = '\0';

  if (c != EOF) ungetch(c);

  return NUMBER;
}

void skipws() {
  int c;
  while ((c = getch()) == ' ' || c == '\t') // skip whitespace
    ;
  if (c != EOF) ungetch(c); // Put back last read non-ws char if not EOF
}

bool isdecpoint(int c) {
  return c == '.';
}

bool isoperator(int c) {
  return !isdigit(c) && c != '.';
}

bool isnegativenum(int c) {
  int next = peekch();
  return c == '-' && (isdigit(next) || isdecpoint(next));
}
