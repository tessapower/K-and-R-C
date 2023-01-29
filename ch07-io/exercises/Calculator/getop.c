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

char line[MAXOP];
size_t len = 0;
int lp = 0;

/**
 * @brief Get next operator or numeric operand
*/
int getop(char s[]) {
  // Skip whitespace
  skipws();

  if (line[lp] == '\0') {
    // If we reached the end of this line, get the next line
    if (scanf("%s", line) == 0) return EOF;

    // Reset pointer to beginning
    lp = 0;
    // Skip leading whitespace
    skipws();
  }

  int i = 0;
  int c = line[lp++];
  s[i++] = c;
  s[i] = '\0';

  if (c == VAR_ACCESS && isvalidvarname(line[lp])) s[0] = line[lp++];

  if (!isnum(c)) return c;

  // Collect integer part digits
  while (isdigit(line[lp])) s[i++] = line[lp++];

  if (isdecpoint(line[lp])) {
    // Add the decimal point
    s[i++] = line[lp++];
    // Collect fractional digits
    while (isdigit(line[lp])) s[i++] = line[lp++];
  }

  s[i] = '\0';

  return NUMBER;
}

void skipws(void) {
  while (isspace(line[lp])) lp++;
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
  const int next = line[lp];
  return c == '-' && (isdigit(next) || isdecnum(next));
}

bool isdecnum(const int c) {
  const int next = line[lp];
  return (isdecpoint(c) && isdigit(next)) || (isdigit(c) && isdecpoint(next));
}

bool iscommand(const int c) {
  return c == PRINT || c == SWAP || c == DUPLICATE || c == CLEAR;
}

bool isvalidvarname(const int c) {
  return (c >= 'a' && c <= 'z') || c == VAR_ACCESS;
}
