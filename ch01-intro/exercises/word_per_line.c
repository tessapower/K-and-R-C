#include <stdio.h>

#define IN  1
#define OUT 0

// Exercise 1-12: Write a program that prints its input one word per line.
int main() {
  int c;
  int state = OUT;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
    } else {
      if (state == OUT) {
        state = IN;
        putchar('\n');
      }
      putchar(c);
    }
  }

  return 0;
}
