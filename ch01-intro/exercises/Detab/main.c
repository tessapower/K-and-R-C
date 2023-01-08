#include <stdio.h>

#define MAX_LINE 1000  // Maximum input line size
#define TAB_INCREMENT 8

/**
 * @brief Reads a line into s with max length of maxlen, returns the length.
*/
int getline(char s[], const int maxlen);

/**
 * @brief Replaces tabs with spaces in s.
*/
void detab(char s[]);

/**
 * @brief Copy the characters from one string to another. The to string
 *  must be large enough.
*/
void copy(char to[], char from[]);

// Exercise 1-20: Write a program detab that replaces tabs in the input with
//  the proper number of blanks to space to the next tab stop. Assume a fixed
//  set of tab stops, say every n columns.
int main() {
  int linelen;
  char line[MAX_LINE];

  while ((linelen = getline(line, MAX_LINE)) > 0) {
    if (line[0] != '\n') {
      detab(line);
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

void detab(char s[]) {
  char tmp[MAX_LINE];

  // Add characters to a temp string so we can insert spaces where needed
  int i = 0;
  int j = 0;
  while (s[i] != '\0' && i < MAX_LINE - 1 && j < MAX_LINE - 1) {
    if (s[i] == '\t') {
      // Calculate spaces needed until the next tabstop position
      const int nspaces = TAB_INCREMENT - (j % TAB_INCREMENT);
      // Insert spaces
      for (int k = 0; k < nspaces; ++k) tmp[j++] = ' ';
    } else {
      tmp[j++] = s[i];
    }

    i++;
  }
  tmp[j] = '\0';

  // Copy temp string into s
  copy(s, tmp);
}

void copy(char to[], char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
