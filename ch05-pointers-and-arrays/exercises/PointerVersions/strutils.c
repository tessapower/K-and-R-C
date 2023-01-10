#include "strutils.h"

#include <ctype.h>
#include <stdio.h>

// Exercise 5-6: Rewrite appropriate programs from earlier chapters and 
//  exercises with pointers instead of array indexing.

void escape(char *s, char *t) {
  while (*t != '\0') {
    int c = *t++;
    switch (c) {
      case '\a': {
        *s++ = '\\';
        *s++ = 'a';
        break;
      }
      case '\b': {
        *s++ = '\\';
        *s++ = 'b';
        break;
      }
      case '\f': {
        *s++ = '\\';
        *s++ = 'f';
        break;
      }
      case '\t': {
        *s++ = '\\';
        *s++ = 't';
        break;
      }
      case '\v': {
        *s++ = '\\';
        *s++ = 'v';
        break;
      }
      case '\r': {
        *s++ = '\\';
        *s++ = 'r';
        break;
      }
      case '\n': {
        *s++ = '\\';
        *s++ = 'n';
        break;
      }
      case '\\': {
        *s++ = '\\';
        *s++ = '\\';
        break;
      }
      case '\'': {
        *s++ = '\\';
        *s++ = '\'';
        break;
      }
      case '\"': {
        *s++ = '\\';
        *s++ = '\"';
        break;
      }
      case '\?': {
        *s++ = '\\';
        *s++ = '\?';
        break;
      }
      default: {
        *s++ = c;
        break;
      }
    }
  }

  // Add terminating character
  *s = '\0';
}

void unescape(char *s, char *t) {
  while (*t != '\0') {
    int c = *t++;
    switch (c) {
      case '\\': {
        if (*t != '\0') {
          int ch = *t++;
          switch (ch) {
            case 'a': {
              *s++ = '\a';
              break;
            }
            case 'b': {
              *s++ = '\b';
              break;
            }
            case 'f': {
              *s++ = '\f';
              break;
            }
            case 't': {
              *s++ = '\t';
              break;
            }
            case 'v': {
              *s++ = '\v';
              break;
            }
            case 'r': {
              *s++ = '\r';
              break;
            }
            case 'n': {
              *s++ = '\n';
              break;
            }
            case '\\': {
              *s++ = '\\';
              break;
            }
            case '\'': {
              *s++ = '\'';
              break;
            }
            case '\"': {
              *s++ = '\"';
              break;
            }
            case '\?': {
              *s++ = '\?';
              break;
            }
          }
        }
        break;
      }
      default: {
        *s++ = c;
        break;
      }
    }
  }

  // Add terminating character
  *s = '\0';
}

double stof(const char *s) {
  while (isspace(*s)) s++; // skip whitespace

  int sign = (*s == '-') ? -1 : 1;
  if (*s == '+' || *s == '-') s++; // skip sign

  // integer part
  double val = 0.0;
  while (isdigit(*s)) {
    val = 10.0 * val + (*s - '0');
    s++;
  }

  // fractional part
  if (*s == '.') s++; // skip point

  double power = 1.0;
  while (isdigit(*s)) {
    val = 10.0 * val + (*s - '0');
    power *= 10.0;
    s++;
  }

  // exponent part
  if (tolower(*s) == 'e') s++; // skip e/E
  int expsign = (*s == '-') ? -1 : 1;
  if (*s == '+' || *s == '-') s++; // skip exponent sign

  double exp = 0;
  while (isdigit(*s)) {
    exp = 10.0 * exp + (*s - '0');
    s++;
  }

  double mult = (expsign < 0) ? 10 : 0.1;
  for (int j = 0; j < exp; ++j) {
    power *= mult;
  }

  return sign * val / power;
}
