#include "strutils.h"
#include <string.h>

// Exercise 3-4: In a two's complement number representation, our version of
//  itoa does not handle the largest negative number, that is, the value of n
//  equal to -(2^(wordsize - 1)). Explain why not. Modify it to print that
//  value correctly, regardless of the machine on which it runs.

// Negating the int value of the largest negative number produces the largest
// positive number + 1, which overflows the int and causes it to wrap. The new
// value is yet again the largest negative value, so the do-while loop runs
// only once and we get a garbage string.
void itoa2(int n, char s[]) {
  int sign = n;
  if (sign < 0) n = -n;

  size_t i = 0;
  do {
    int d = n % 10;
    if (d < 0) d = -d;
    s[i++] = d + '0';
  } while ((n /= 10) != 0);

  if (sign < 0) s[i++] = '-';

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
