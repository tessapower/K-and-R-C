#include <stdio.h>
#include <string.h>
#include "strutils.h"

// Exercise 2-3: Write the function htoi(s), which converts a string of hex
//  digits (including an optional 0x or 0X) into its equivalent integer value.
//  The allowable digits are 0 through 9, a through f, and A through F.
int main() {
  printf("0 to 10 in hex:\n");
  printf("0\t%#x\n", htoi("0x0"));
  printf("1\t%#x\n", htoi("0x1"));
  printf("2\t%#x\n", htoi("0x2"));
  printf("3\t%#x\n", htoi("0x3"));
  printf("4\t%#x\n", htoi("0x4"));
  printf("5\t%#x\n", htoi("0x5"));
  printf("6\t%#x\n", htoi("0x6"));
  printf("7\t%#x\n", htoi("0x7"));
  printf("8\t%#x\n", htoi("0x8"));
  printf("9\t%#x\n", htoi("0x9"));
  printf("10\t%#x\n", htoi("0xA"));

  return 0;
}
