#include "strutils.h"

#include <stdio.h>

void itostr(int n, char s[]) {
  static int i;

  if (n / 10) {
    itostr(n / 10, s);
  } else {
    i = 0;
    if (n < 0) s[i++] = '-';
  }

  int d = n % 10;
  if (d < 0) d = -d;
  s[i++] = d + '0';
  s[i] = '\0';
}
