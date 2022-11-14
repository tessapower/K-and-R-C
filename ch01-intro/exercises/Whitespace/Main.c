#include <stdio.h>

// Exercise 1-8: Write a program to count blanks, tabs, and newlines.
int main() {
  int c;
  int nl = 0;
  int t = 0;
  int s = 0;

  printf("> ");

  while ((c = getchar()) != EOF) {
    if (c == ' ') ++s;

    if (c == '\t') ++t;

    if (c == '\n') ++nl;
  }

  printf("Blanks: %d\nTabs: %d\nNewlines: %d\n", s, t, nl);

  return 0;
}
