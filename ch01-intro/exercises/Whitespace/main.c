#include <stdio.h>

// Exercise 1-8: Write a program to count blanks, tabs, and newlines.
int main() {
  int s = 0;
  int t = 0;
  int nl = 0;

  printf("> ");

  int c;
  while ((c = getchar()) != EOF) {
    if (c ==  ' ') ++s;
    if (c == '\t') ++t;
    if (c == '\n') ++nl;
  }

  printf("sp: %d\nht: %d\nlf: %d\n", s, t, nl);

  return 0;
}
