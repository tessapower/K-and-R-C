#include "strutils.h"

#include <assert.h>
#include <string.h>

// Exercise 5-5: Write versions of the library functions strncpy, strncat, and
//  strncmp, which operate on at most the first n characters of their argument
//  strings. For example, strncpy(s, t, n) copies at most n characters of t to
//  s.

void strncopy(char* s, char* t, int n) {
  // Return early if n is a nonsense value
  if (n <= 0) return;

  int i = 0;
  while (i++ < n && (*s++ = *t++))
    ;

  // We need to add the null character because this may not have been included
  // in the n characters
  *s = '\0';
}

void strnconcat(char* s, char* t, int n) {
  // Return early if n is a nonsense value
  if (n <= 0) return;

  // Find end of s
  while (*s != '\0')
    s++;

  // Copy t
  int i = 0;
  while (i++ < n && (*s++ = *t++))
    ;

  // We need to add the null character because this may not have been included
  // in the n characters
  *s = '\0';
}

int strncomp(char* s, char* t, int n) {
  int i = 0;
  for ( ; i < n && *s == *t; i++, s++, t++) {
    if (*s == '\0') return 0;
  }

  if (i == n) return 0;

  return *s - *t;
}
