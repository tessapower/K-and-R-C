#include <stdio.h>
#include "StrUtils.h"

#define IN  1
#define OUT 0

// Reads a line into s, returns the length
int getLine(char s[]) {
  int c;
  // Declare i outside of loop so we can return the length
  int i;
  for (i = 0; i < MAX_LINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  // Handle end of line
  if (c == '\n') {
    // Add final newline char
    s[i] = c;
    ++i;
  }
  // Add string termination char
  s[i] = '\0';

  return i;
}

// Folds a line into two or more shorter lines of the given maximum length
void fold(char s[], const int lim) {
  char tmp[MAX_LINE];

  int i = 0;
  int j = 0;
  int c = '\0';
  int col = 0;
  int state = OUT;
  int foldIdx = -1;
  while (s[i] != '\0' && i < MAX_LINE && j < MAX_LINE - 1) {
    c = s[i++];

    // Set foldIdx
    if (c == ' ' || c == '\t' || c == '\n') {
      if (state == IN) foldIdx = j;
      state = OUT;
    } else if (state == OUT) {
      state = IN;
    }

    // Handle folding line once we've reached the fold limit
    if (col == lim) {
      if (state == IN) {
        if (foldIdx != -1) {
          tmp[foldIdx] = '\n';
          col = j - foldIdx;
        } else {
          tmp[j++] = '\n';
          col = 0;
        }
      } else {
        c = '\n';
        col = 0;
      }
    }

    tmp[j++] = c;
    col++;
  }

  // Handle end of line
  if (c == '\n') {
    tmp[j++] = c;
  }
  tmp[j] = '\0';

  copy(s, tmp);
}

void copy(char to[], char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
