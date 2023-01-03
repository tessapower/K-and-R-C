#include <stdio.h>

#define IN 1
#define OUT 0

// Exercise 1-12: Write a program that prints its input one word per line.
int main() {
  int c;
  int state = OUT;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN) { // end of the word
        state = OUT;
        putchar('\n');
      }
    } else {
      if (state == OUT) { // end of the word
        state = IN;
      }
      putchar(c);
    }
  }

  return 0;
}
