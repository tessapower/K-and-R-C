#include <stdio.h>

#define MAX_LINE 1000  // Maximum input line size

/**
 * @brief Reads a line into s with max length of maxline, returns the length.
*/
int getline(char line[], int maxline);

/**
 * @brief Removes trailing spaces and tabs from s.
*/
int rm(char s[], int len);

// Exercise 1-18: Write a program to remove trailing blanks and tabs from each
//  line of input, and to delete entirely blank lines.
int main() {
  int linelength;
  char line[MAX_LINE];

  while ((linelength = getline(line, MAX_LINE)) > 0) {
    if (rm(line, linelength) > 0) {
      printf("%s", line);
    }
  }

  return 0;
}

// Reads a line into s, returns the length
int getline(char s[], int lim) {
  int c = 0;
  // Declare i outside of loop so we can return the length
  int i;
  for (i = 0; i < lim - 2 && (c = getchar()) != EOF && c != '\n'; ++i) {
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

int rm(char s[], int len) {
  int i = len - 1;
  
  // ignore newline char for now
  int newline = s[i] == '\n';
  if (newline) {
    --i;
  }

  // return early if string is empty
  if (i < 0) return i;

  // Handle trailing whitespace
  while (i >= 0 && (s[i] == ' ' || s[i] == '\t')) {
    --i;
  }
  
  if (i >= 0) {
    // Add back newline char
    if (newline) s[++i] = '\n';

    // Add string termination char
    s[++i] = '\0';
  }

  return i;
}
