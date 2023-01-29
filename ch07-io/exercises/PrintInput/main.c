#include <stdio.h>
#include <ctype.h>

#define MAXLEN 80
#define HEXWIDTH 4

// Exercise 7-2: Write a program that will print arbitrary input in a sensible
//  way. As a minimum, it should print non-graphic characters in octal or
//  hexadecimal according to local custom, and break long text lines.

int main(int argc, char** argv) {
  int col = 0;
  int c = 0;
  // Read input character by character
  while ((c = getchar()) != EOF) {
    // non-graphical chars
    if (!isprint(c)) {
      // make sure it'll fit on this line
      if (col + HEXWIDTH > MAXLEN) {
        putchar('\n');
        col = 0;
      }

      // print in hex
      printf("0x%0*x", HEXWIDTH, c);
      col += HEXWIDTH;

      continue;
    }

    // Break long lines of text
    col = (c == '\n' || col == MAXLEN) ? 0 : col + 1;

    putchar(c);
  }

  return 0;
}
