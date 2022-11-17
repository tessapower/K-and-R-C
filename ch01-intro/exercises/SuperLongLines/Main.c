#include <stdio.h>
#include <limits.h>

#define MAX_LINE SHRT_MAX  // Maximum input line size

int getLine(char line[], int maxLine);

// Exercise 1-16: Revise the main routine of the longest line program so it
//  will correctly print the length of arbitrarily long input lines, and as
//  much as possible of the text.
int main() {
  int lineLength;
  char line[MAX_LINE];

  while ((lineLength = getLine(line, MAX_LINE)) > 0) {
    printf("%d\n", lineLength);
    printf("%s", line);
  }

  return 0;
}

// Reads a line into s, returns the length
int getLine(char s[], int lim) {
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
