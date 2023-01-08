#include <stdio.h>

#define MAX_LINE 1000  // Maximum input line size

/**
 * @brief Reads a line into s with max length of maxlen, returns the length.
*/
int getline(char line[], int maxlen);

/**
 * @brief Reverses the string s in place.
*/
void reverse(char line[]);

/**
 * @brief Swaps the characters at the indices i and j in s.
*/
void swap(char s[], int i, int j);

// Exercise 1-19: Write a function reverse(s) that reverses the character
//  string s. Use it to write a program that reverses its input a line at a
//  time.
int main() {
  int linelen;
  char line[MAX_LINE];

  while ((linelen = getline(line, MAX_LINE)) > 0) {
    if (line[0] != '\n') {
      reverse(line);
      printf("%s", line);
    }
  }

  return 0;
}

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

void reverse(char line[]) {
  int len;
  for (len = 0; line[len] != '\0'; ++len)
    ;

  // Leave the newline in place
  if (line[len - 1] == '\n') len--;

  for (int i = 0; i < len / 2; i++) {
    swap(line, i, len - i - 1);
  }
}

void swap(char s[], int i, int j) {
  char tmp = s[i];
  s[i] = s[j];
  s[j] = tmp;
}
