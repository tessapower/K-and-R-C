#include "ioutils.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int getword(char* word, int lim) {
  int c = 0;
  char* w = word;

  if (peekch() != EOF) {
    *w++ = (c = getch());
  } else {
    // We have reached the end of input, so discard EOF and terminate string
    getch();
    *w = '\0';

    return EOF;
  }
  
  // Word, underscore, or preprocessor directive
  if (isalpha(c) || c == '_' || c == '#') {
    while (--lim > 0 && (c = peekch()) != EOF) {
      if (!(isalnum(c) || c == '_')) break;

      *w++ = getch();
    }
  }

  *w = '\0';
  return word[0];
}

void getname(char* name, int lim) {
  int c = 0;

  // Skip any leading whitespace
  skipws();

  int res = getword(name, lim);

  if (!(isalpha(res) || res == '_')) {
    // print error message and exit
    error("error: invalid name for #define directive");
  }
}

void getdef(char* s, int lim) {
  // Skip any leading whitespace
  skipws();

  // Collect everything until the end of the line
  while (--lim > 0 && peekch() != EOF && peekch() != '\n') *s++ = getch();

  if (peekch() == '\n') getch(); // consume newline character

  // Add terminating character
  *s = '\0';
}

void skipws(void) {
  int c = 0;
  while (isspace(c = peekch())) getch();
}

void error(char* msg) {
  printf("%s", msg);

  exit(-1);
}

#include <string.h>

void ungets(const char s[]) {
  size_t i = strlen(s);
  // First push back an EOF character
  ungetch(EOF);
  // We push back the string backwards so that when rereading from the input
  // buffer, it will appear in the same order as if read from stdin.
  while (i > 0 && ungetch(s[--i]))
    ;
}

#define BUFSIZE 1024
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
