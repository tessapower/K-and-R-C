#include "strutils.h"
#include <assert.h>
#include <string.h>

// Exercise 3-5: Write the function itob(n, s, b) that converts the integer n
//  into a base b character representation in the string s. In particular,
//  itob(n, s, 16) formats n as a hex integer in s.
void itob(int n, char s[], const int b) {
  assert(b > 1 && b <= 16);

  if (b == 10) {
    itostr(n, s);
    return;
  }

  int sign = n;
  unsigned num = (unsigned int)n;

  size_t i = 0;
  do {
    int d = num % b;
    if (d < 0) d = -d;
    if (d >= 10) {
      d -= 10;
      d = d + 'a';
    } else {
      d = d + '0';
    }
    s[i++] = d;
  } while ((num /= b) != 0);

  s[i] = '\0';

  reverse(s);
}

void itostr(int n, char s[]) {
  int sign = n;
  if (n < 0) n = -n;

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
