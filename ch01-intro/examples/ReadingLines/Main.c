#include <stdio.h>

#define MAX_LINE 1000  // Maximum input line size

int getLine(char line[], int maxLine);
void copy(char to[], char from[]);

// Read lines from the standard in and print the longest one
int main() {
  int currentLineLength;
  char currentLine[MAX_LINE];

  char longestLine[MAX_LINE];
  int maxLength = 0;

  while ((currentLineLength = getLine(currentLine, MAX_LINE)) > 0) {
    if (currentLineLength > maxLength) {
      maxLength = currentLineLength;
      copy(longestLine, currentLine);
    }
  }

  if (maxLength > 0) {
    printf("%s", longestLine);
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

void copy(char to[], char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
