#include <stdio.h>

#define MAX_LINE 1000  // Maximum input line size

// Exercise 1-18: Write a program to remove trailing blanks and tabs from each
//  line of input, and to delete entirely blank lines.
int getline(char line[], int maxline);

int main() {
  int linelength;
  char line[MAX_LINE];

  while ((linelength = getline(line, MAX_LINE)) > 0) {
    if (line[0] != '\n') {
      printf("%s", line);
    }
  }

  return 0;
}

// Reads a line into s, returns the length
int getline(char s[], int lim) {
  int c;
  // Declare i outside of loop so we can return the length
  int i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  // Handle end of line
  if (c == '\n') {
    // Handle trailing whitespace
    while (i > 0 && (s[i - 1] == ' ' || s[i - 1] == '\t')) {
      --i;
    }

    // Add final newline char
    s[i] = c;
    ++i;
  }
  // Add string termination char
  s[i] = '\0';

  return i;
}
