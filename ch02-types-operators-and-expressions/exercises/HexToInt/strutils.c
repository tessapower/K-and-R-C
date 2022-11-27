#include <stdio.h>
#include <string.h> // strlen
#include <ctype.h> // tolower, isdigit, isalpha
#include "strutils.h"

// Exercise 2-3: Write the function htoi(s), which converts a string of hex
//  digits (including an optional 0x or 0X) into its equivalent integer value.
//  The allowable digits are 0 through 9, a through f, and A through F.
int htoi(const char s[]) {
  int n = 0;

  int i = 0;
  // Return early if the string is empty
  if (strlen(s) == 0) return n;
  // Skip over the optional 0x or 0X if present
  if (s[0] == '0' && tolower(s[1]) == 'x') {
    i += 2;
  }

  while (isxdigit(s[i])) {
    int c = s[i++];
    c = tolower(c);
    int val = 0;
    if (isdigit(c)) {
      val = c - '0';
    } else if (isalpha(c)) {
      val = c - 'a' + 10;
    }
      n = n * 16 + val;
  }

  return n;
}


