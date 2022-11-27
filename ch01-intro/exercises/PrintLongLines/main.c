#include <stdio.h>

#define MIN_LINE 80   // Minimum input line size
#define MAX_LINE 1000 // Maximum input line size

// Exercise 1-17: Write a program to print all input lines that are longer than
//  80 characters.
int getline(char line[], int maxLine);

int main() {
  int lineLength;
  char line[MAX_LINE];

  while ((lineLength = getline(line, MAX_LINE)) > 0) {
    if (lineLength > MIN_LINE) {
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
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}
