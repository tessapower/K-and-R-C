#include "getfloat.h"
#include "getch.h"

#include <stdio.h>
#include <ctype.h>

int getfloat(float* pn) {
  // Skip whitespace
  skipws();

  int c = getch();
  // Handle non-numeric input
  if (!isnum(c) && c != EOF) {
    ungetch(c);

    return 0;
  }

  if (c == EOF) return c;

  int sign = (c == '-') ? -1 : 1;
  // Skip over sign char
  if (issign(c)) c = getch();

  for (*pn = 0; isdigit(c); c = getch()) *pn = 10 * *pn + (c - '0');

  if (isdecpoint(c)) c = getch(); // skip over the optional decimal point

  // optional fractional part
  float power = 1.0f;
  float mantissa = 0.0f;
  while (isdigit(c)) {
    mantissa = 10.0f * mantissa + (c - '0');
    power *= 10.0f;
    c = getch();
  }

  *pn += (mantissa / power);

  // Adjust to correct sign
  *pn *= sign;

  // Push back the last read character because we always read one too many
  if (c != EOF) ungetch(c);

  return c;
}

bool isnum(int c) {
  return isdigit(c) || (isdecpoint(c) && isdigit(peekch())) || (issign(c) && isdigit(peekch()));
}

bool issign(int c) {
  return (c == '+' || c == '-');
}

bool isdecpoint(int c) {
  return c == '.';
}

void skipws(void) {
  while (isspace(peekch())) getch();
}
