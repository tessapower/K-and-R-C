#include <stdio.h>
#include <math.h>
#include <string.h>
#include "getch.h"

void ungets(const char s[]) {
  size_t i = strlen(s);
  // We push back the string backwards so that when rereading from the input
  // buffer, it will appear in the same order as if read from stdin.
  while (i > 0 && ungetch(s[--i]))
    ;
}

#define BUFSIZE 100
int buf[BUFSIZE];
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

bool ungetch(int c) {
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters\n");

    return false;
  }

  buf[bufp++] = c;
  return true;
}

void clearbuf(void) {
  bufp = 0;
}
