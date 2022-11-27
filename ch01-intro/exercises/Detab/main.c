#include <stdio.h>

#define MAX_LINE 1000  // Maximum input line size
#define TAB_WIDTH 8

int getline(char line[], const int maxLine);
void detab(char line[]);
void copy(char to[], char from[]);

// Exercise 1-20: Write a program detab that replaces tabs in the input with
//  the proper number of blanks to space to the next tab stop. Assume a fixed
//  set of tab stops, say every n columns.
int main() {
  int lineLength;
  char line[MAX_LINE];

  while ((lineLength = getline(line, MAX_LINE)) > 0) {
    if (line[0] != '\n') {
      detab(line);
      printf("%s", line);
    }
  }

  return 0;
}

// Reads a line into s, returns the length
int getline(char s[], const int lim) {
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

void detab(char s[]) {
  char tmp[MAX_LINE];

  int i = 0;
  int j = 0;
  while (s[i] != '\0' && i < MAX_LINE - 1 && j < MAX_LINE - 1) {
    if (s[i] == '\t') {
      const int nBlanks = TAB_WIDTH - (j % TAB_WIDTH);
      for (int k = 0; k < nBlanks; ++k) tmp[j++] = ' ';
    } else {
      tmp[j++] = s[i];
    }

    i++;
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
