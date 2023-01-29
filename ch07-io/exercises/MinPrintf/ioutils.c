#include "ioutils.h"

#include <stdio.h>
#include <ctype.h>

// Exercise 7-3: Revise minprintf to handle more of the other facilities of
//  printf.

#define MAX_MODS 16

void minprintf(char* fmt, ...) {
  // Points to each unnamed arg in turn
  va_list ap;
  char* p, *sval;
  char cval;
  int ival;
  double dval;

  // Make ap point to the first unnamed argument
  va_start(ap, fmt);
  for (p = fmt; *p; p++) {
    if (*p != '%') {
      putchar(*p);

      continue;
    }

    // Get modifiers for the format specifier e.g. %10.2f
    char* mods[MAX_MODS];
    int i = 0;
    // First modifier is always the '%' char
    mods[i++] = *p++;
    while (i < MAX_MODS - 1 && !isalpha(*p)) {
      mods[i++] = *p++;
    }
    mods[i] = '\0';

    switch (*++p) {
      case 'd': case 'i': case 'o': case 'u': case 'x': case 'X': {
        ival = va_arg(ap, int);
        printf(mods, ival);
        break;
      }
      case 'a': case 'f': case 'F': case 'g': case 'G': case 'e': case 'E': {
        dval = va_arg(ap, double);
        printf(mods, dval);
        break;
      }
      case 'c': case 'C': {
        cval = va_arg(ap, int);
        printf(mods, cval);
        break;
      }
      case 's': {
        for (sval = va_arg(ap, char*); *sval; sval++) putchar(*sval);
        break;
      }
      default: {
        putchar(*p);
        break;
      }
    }
  }

  va_end(ap);
}
