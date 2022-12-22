#include <stdio.h>

#define MAX_LINE 80  // Maximum input line size
#define TAB_WIDTH 8

int getline(char line[], const int maxLine);
void entab(char line[]);
void copy(char to[], char from[]);

// Exercise 1-21: Write a program entab that replaces strings of blanks by the
//  minimum number of tabs and blanks to achieve the same spacing. Use the
//  same tab stops as for detab.
int main() {
  int lineLength;
  char line[MAX_LINE];

  while ((lineLength = getline(line, MAX_LINE)) > 0) {
    if (line[0] != '\n') {
      entab(line);
      printf("%s", line);
    }
  }

  return 0;
}

// Reads a line into s, returns the length
int getline(char s[], const int lim) {
  int c = 0;
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

  int ntabs = 0;
  int nblanks = 0;
  while (s[i] != '\0' && i < MAX_LINE && j < MAX_LINE - 1) {
    // Move along the string, copy chars until we hit a blank
    if (s[i] == ' ') {
      // Collect blanks until we get enough to need a tab
      if (i % TAB_WIDTH == 0) {
        nblanks = 0;
        ntabs++;
      } else {
        nblanks++;
      }
    } else {
      // If we have been collecting blanks and tabs, add them before adding
      // a new character, making sure we don't go over the max line length.
      // Does nothing if ntabs and nblanks is 0.
      while (ntabs-- > 0 && j < MAX_LINE - 1) tmp[j++] = '\t';
      while (nblanks-- > 0 && j < MAX_LINE - 1) tmp[j++] = ' ';
      // Reset tabs & blanks
      ntabs = 0;
      nblanks = 0;

      // Add the character
      tmp[j++] = s[i];
      i++;
    }
  }

  // Add terminating character
  tmp[j] = '\0';

  // Copy our tmp string back into s
  copy(s, tmp);
}

void copy(char to[], char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
