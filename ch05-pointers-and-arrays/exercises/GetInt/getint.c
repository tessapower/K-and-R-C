#include "getint.h"
#include "getch.h"

#include <stdio.h>
#include <ctype.h>

int getint(int* pn) {
  // Skip whitespace
  while (isspace(peekch()))
    getch();

  int c = getch();
  // Handle non-numeric input
  if (!isnum(c) && c != EOF) {
    ungetch(c);

    return 0;
  }

  if (c == EOF) return c;

  int sign = (c == '-') ? -1 : 1;
  // Skip over sign char
  if (c == '+' || c == '-') c = getch();
  
  for (*pn = 0; isdigit(c); c = getch()) *pn = 10 * *pn + (c - '0');
  ungetch(c);

  // Adjust to correct sign
  *pn *= sign;

  return c;
}

bool isnum(int c) {
  return isdigit(c) || issigned(c);
}

bool issigned(int c) {
  return (c == '+' || c == '-') && isdigit(peekch());
}
