#include "strutils.h"

#include <stdio.h>
#include <ctype.h>

// Exercise 6-1: Our version of getword does not properly handle underscores,
//  string constants, comments, or preprocessor control lines. Write a better
//  version.

int getword(char* word, int lim) {
  int c = 0;
  char* w = word;

  skipws();

  if (peekch() != EOF)
    *w++ = (c = getch());
  
  // Word, underscore, or preprocessor directive
  if (isalpha(c) || c == '_' || c == '#') {
    for (; --lim > 0; w++) {
      c = peekch();
      if (!(isalnum(c) || c == '_')) break;

      *w = getch();
    }
  } else if (c == '/') { // Maybe a comment
    int next = peekch();
    if (next == '/' || next == '*') { // Definitely a comment
      ungetch(c); // First put back initial slash character, then skip comment
      skipcomment();

      // recurse to get next word, skipping further ws, comments, or strings
      return getword(word, lim);
    }
  } else if (c == '"' || c == '\'') { // string constant
    ungetch(c); // First put back the initial quote character, then skip string
    skipstring();

    // recurse to get next word, skipping further ws, comments, or strings
    return getword(word, lim);
  }

  *w = '\0';
  return word[0];
}

void skipws(void) {
  while (isspace(peekch())) getch();
}

void skipcomment(void) {
  int c = peekch();

  if (c == '/') {
    c = getch();
    if (peekch() == '/') { // Single line comment
      while ((c = peekch()) != EOF && c != '\n') getch();
    } else if (peekch() == '*') { // Multi-line comment
      // Skip over asterisk
      getch();
      while (peekch() != EOF) {
        if ((c = getch()) == '*' && peekch() == '/') {
          getch(); // get final comment character

          break;
        }
      }
    } else { // Not a comment, push back the slash
      ungetch(c);
    }
  }
}

void skipstring(void) {
  int c = peekch();
  if (c == '\'' || c == '"') {
    int quote = getch();
    while ((c = peekch()) != EOF) {
      getch();
      if (c == quote) break;
    }
  }
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

#define BUFSIZE 512
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
