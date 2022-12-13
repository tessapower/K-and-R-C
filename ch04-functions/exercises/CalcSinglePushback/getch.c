#include <stdio.h>
#include "calc.h"

int bufch = -1;

int peekch(void) {
  if (bufch != -1) return bufch;

  const int c = getchar();
  ungetch(c);

  return c;
}

int getch(void) {
  if (bufch == -1) return getchar();
  
  const int ch = bufch;
  bufch = -1;

  return ch;
}

bool ungetch(int c) {
  if (bufch != -1) {
    printf("ungetch: too many characters\n");

    return false;
  }

    bufch = c;

    return true;
}

void clearbuf(void) {
  bufch = -1;
}