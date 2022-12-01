#include <stdio.h>
#include "strutils.h"

#define LEN 50

int main() {
  char t[LEN] = "Hello\n,\tworld!\?\r\n";
  char s[LEN];
  escape(s, t);
  printf("%s", t);
  printf("\"%s\"\n", s);

  return 0;
}
