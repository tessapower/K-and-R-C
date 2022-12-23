#include "strutils.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

int readlines(char* lineptr[], const int maxlines, int (*getc)(void)) {
  int nlines = 0;

  // Pointer to next free section of memory in our buffer
  char *p = NULL;
  int len = 0;
  char line[MAXLEN];
  while ((len = getline(line, MAXLEN, getc)) > 0) {
    if (nlines >= maxlines || (p = alloc(len)) == NULL) return -1;

    // Delete newline character
    line[len - 1] = '\0';
    strcpy_s(p, len, line);
    lineptr[nlines++] = p;
  }

  return nlines;
}

int getline(char* line, const int maxlen, int (*getc)(void)) {
  int i = 0;
  int c = 0;
  // Collect all the characters
  while ((c = getc()) != EOF && c != '\n' && c != '\0') line[i++] = c;

  // Add new line character
  if (c == '\n') line[i++] = c;

  // Add terminating character
  line[i] = '\0';

  return i;
}

void writelines(char* lineptr[], const int nlines) {
  for (int i = 0; i < nlines; ++i) printf("%s\n", *lineptr++);
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(const int n) {
  // Check if it doesn't fit
  if (allocbuf + ALLOCSIZE - allocp < n) {
    return 0;
  }

  // Move pointer along to next free section
  allocp += n;
  // Return old pointer position
  return allocp - n;
}

/**
 * @brief Free storage pointed to by p
*/
void afree(char* p) {
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE) allocp = p;
}
