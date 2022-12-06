#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/**
 * @brief Get next operator or numeric operand
*/
int getop(char s[]) {
  int c;
  while ((s[0] = c = getch()) == ' ' || c == '\t') // skip whitespace
    ;

  s[1] = '\0';
  if (!isdigit(c) && c != '.') return c; // Not a number

  int i = 0;
  // Collect integer part
  if (isdigit(c)) {
    while (isdigit(s[++i] = c = getch()))
      ;
  }

  // Collect fraction part
  if (c == '.') {
    while (isdigit(s[++i] = c = getch()))
      ;
  }

  s[i] = '\0';

  if (c != EOF)
    ungetch(c);

  return NUMBER;
}
