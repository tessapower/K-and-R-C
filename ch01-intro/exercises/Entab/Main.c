#include <stdio.h>

#define MAX_LINE 80  // Maximum input line size
#define TAB_WIDTH 8

int getLine(char line[], const int maxLine);
void entab(char line[]);
void copy(char to[], char from[]);

// Exercise 1-21: Write a program entab that replaces strings of blanks by the
//  minimum number of tabs and blanks to achieve the same spacing. Use the
//  same tab stops as for detab.
int main() {
  int lineLength;
  char line[MAX_LINE];

  while ((lineLength = getLine(line, MAX_LINE)) > 0) {
    if (line[0] != '\n') {
      entab(line);
      printf("%s", line);
    }
  }

  return 0;
}

// Reads a line into s, returns the length
int getLine(char s[], const int lim) {
  int c;
  // Declare i outside of loop so we can return the length
  int i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  // Handle end of line
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}

void entab(char s[]) {
  char tmp[MAX_LINE];

  int i = 0;
  int j = 0;
  while (s[i] != '\0' && i < MAX_LINE - 1 && j < MAX_LINE - 1) {
    // move along the string and copy chars until we hit a space
    if (s[i] == ' ') {
      int nTabs = 0;
      int nBlanks = 0;
      // look forward until we find the next non-space char
      int start = i;
      while (s[i] == ' ' && i < MAX_LINE - 1) {
        nBlanks++;
        i++;
        // if we crossed over a tab stop
        if (i % TAB_WIDTH == 0) {
          nBlanks = 0;
          nTabs++;
        }
      }

      for (int k = 0; k < nTabs; ++k) tmp[j++] = '_';
      for (int k = 0; k < nBlanks; ++k) tmp[j++] = '.';
    } else {
      tmp[j++] = s[i];
      i++;
    }
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
