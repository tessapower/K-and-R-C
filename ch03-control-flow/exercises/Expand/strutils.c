#include "strutils.h"
#include <ctype.h>

// Exercise 3-3: Write a function expand(s1, s2) that expands shorthand
//  notations like a-z on the string s1 into the equivalent complete list
//  abc...xyz in s2. Allow for letters of either case and digits, and be
//  prepared to handle cases like a-b-c, a-z0-9, and -a-z. Arrange that a
//  leading or trailing - is taken literally.
void expand(char s1[], char s2[]) {
  int i = 0;
  int j = 0;
  int lastc = 0;
  while (s1[i] != '\0') {
    const int c = s1[i];

    if (lastc == '-' && i > 1 && isvalidrange(s1[i - 2], c)) {
      // decrease j by one so we overwrite the - character
      j--;
      int start = s1[i - 2] + 1;
      int end = c;

      for (int k = start; k < end; ++k) {
        s2[j++] = k;
      }
    }

    s2[j++] = c;
    i++;
    lastc = c;
  }

  s2[j] = '\0';
}

bool isvalidrange(const int start, const int end) {
  if (start >= end) return false;
  if (isalpha(start)) return (isupper(start) == isupper(end)) && isalpha(end);
  if (isdigit(start)) return isdigit(end);

  return false;
}
