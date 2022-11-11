#include <stdio.h>

// Exercise 1-9: Write a program to copy its input to its output, replacing
//   each string of one or more blanks by a single blank.
int main() {
  int c;

  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == '\t' || c == ' ') {
      // collect the blanks of this type
      int b = c;
      while ((c = getchar()) == b)
        ;

      ungetc(c, stdin );
      c = b;
    }

    putchar(c);
  }

  return 0;
}
