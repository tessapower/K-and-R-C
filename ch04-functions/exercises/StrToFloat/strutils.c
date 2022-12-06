#include "strutils.h"

#include <ctype.h>

// Exercise 4-2: Extend atof to handle scientific notation in the form
//  123.45e-6 where a floating point number may be followed by e or E and an
//  optionally signed exponent.
double stof(const char s[]) {
  int i = 0;
  while (isspace(s[i])) ++i; // skip whitespace
  
  int sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') ++i; // skip sign

  // integer part
  double val = 0.0;
  while (isdigit(s[i])) {
    val = 10.0 * val + (s[i] - '0');
    ++i;
  }

  // fractional part
  if (s[i] == '.') ++i; // skip point

  double power = 1.0;
  while (isdigit(s[i])) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
    ++i;
  }

  // exponent part
  if (tolower(s[i]) == 'e' ) ++i; // skip e/E
  int expsign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') ++i; // skip exponent sign

  double exp = 0;
  while (isdigit(s[i])) {
    exp = 10.0 * exp + (s[i] - '0');
    ++i;
  }

  double mult = (expsign < 0) ? 10 : 0.1;
  for (int j = 0; j < exp; ++j) {
    power *= mult;
  }

  return sign * val / power;
}
