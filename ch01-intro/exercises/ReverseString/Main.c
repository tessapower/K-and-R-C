#include <stdio.h>

#define MAX_LINE 1000  // Maximum input line size

int getLine(char line[], int maxLine);
void reverse(char line[]);
void swap(char s[], int i, int j);

// Exercise 1-19: Write a function reverse(s) that reverses the character
//  string s. Use it to write a program that reverses its input a line at a
//  time.
int main() {
  int lineLength;
  char line[MAX_LINE];

  while ((lineLength = getLine(line, MAX_LINE)) > 0) {
    if (line[0] != '\n') {
      reverse(line);
      printf("%s\n", line);
    }
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

  s[i] = '\0';

  return i;
}

void reverse(char line[]) {
  int len;
  for (len = 0; line[len] != '\0'; ++len)
    ;

  for (int i = 0; i < len / 2; i++) {
    swap(line, i, len - i - 1);
  }
}

void swap(char s[], int i, int j) {
  char tmp = s[i];
  s[i] = s[j];
  s[j] = tmp;
}
