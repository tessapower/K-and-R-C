#include <stdio.h>
#include "calc.h"

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int peekch(void) {
  if (bufp > 0) return buf[bufp - 1];

  const char c = getchar();
  ungetch(c);

  return c;
}

int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
  if (bufp >= BUFSIZE) printf("ungetch: too many characters\n");
  else buf[bufp++] = c;
}

void clearbuf(void) {

  bufp = 0;
}