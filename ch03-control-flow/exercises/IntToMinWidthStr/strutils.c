#include "strutils.h"

#include <assert.h>
#include <string.h>

// Exercise 3-6: Write a version of itoa that accepts three arguments instead
//  of two. The third argument is a minimum field width; the converted number
//  must be padded with blanks on the left if necessary to make it wide enough.

void itostr(int n, char s[], const int w) {
  assert(w >= 0);

  int sign = n;
  if (n < 0) n = -n;

  size_t i = 0;
  do {
    int d = n % 10;
    if (d < 0) d = -d;
    s[i++] = d + '0';
  } while ((n /= 10) != 0);

  if (sign < 0) s[i++] = '-';

  while (i < w) {
    s[i++] = ' ';
  }

  s[i] = '\0';

  reverse(s);
}

void reverse(char s[]) {
  size_t i, j;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    int c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}


