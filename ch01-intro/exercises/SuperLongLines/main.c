#include <stdio.h>
#include <limits.h>

#define MAX_LINE SHRT_MAX // Maximum input line size

int getline(char line[], int maxline);

// Exercise 1-16: Revise the main routine of the longest line program so it
//  will correctly print the length of arbitrarily long input lines, and as
//  much as possible of the text.
int main() {
  int linelength;
  char l[MAX_LINE];

  while ((linelength = getline(l, MAX_LINE)) > 0) {
    printf("%d\n", linelength);
    printf("%s", l);
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
