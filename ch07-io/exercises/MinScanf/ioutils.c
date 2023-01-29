#include "ioutils.h"

#include <stdio.h>
#include <ctype.h>

// Exercise 7-4: Write a private version of scanf analogous to minprintf from
//  the previous section.

#define MAX_MODS 16

void minscanf(const char *fmt, ...) {
  va_list ap;
  char* sval;
  char cval;
  int* ival;
  double* dval;
  unsigned* uval;

  // Make ap point to the first unnamed argument
  va_start(ap, fmt);

  // Get modifiers for the format specifier e.g. %10.2f
  char* mods[MAX_MODS];
  int i = 0;
  char* p = fmt;
  while (*p) {
    if (*p == '%') {
      // Add % character to modifiers
      mods[i++] = *p++;
      // Collect the modifiers
      while (i < MAX_MODS - 1 && *p && !isalpha(*p)) {
        mods[i++] = *p++;
      }
      // Format specifier character
      mods[i++] = *p;
      // String terminating character
      mods[i] = '\0';
    }
    i = 0;

    switch (*p++) {
      case 'd': case 'i': {
        ival = va_arg(ap, int*);
        scanf(mods, ival);
        break;
      }
      case 'o': case 'u': case 'x': case 'X': {
        uval = va_arg(ap, unsigned*);
        scanf(mods, uval);
        break;
      }
      case 'a': case 'f': case 'F': case 'g': case 'G': case 'e': case 'E': {
        dval = va_arg(ap, double*);
        scanf(mods, dval);
        break;
      }
      case 'c': case 'C': {
        cval = va_arg(ap, int*);
        scanf(mods, cval);
        break;
      }
      case 's': {
        va_arg(ap, char*);
        scanf(mods, sval);
        break;
      }
      default: {
        scanf(mods);
        break;
      }
    }
  }

  va_end(ap);
}
