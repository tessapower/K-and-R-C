#include <stdio.h>

// Exercise 1-6: Verify that the expression `getchar() != EOF` is 0 or 1.
// Exercise 1-7: Write a program to print the value of `EOF`.

int main() {
  printf("(getchar() != EOF) = %d\n", getchar() != EOF);
  printf("EOF = %d\n", EOF);

  return 0;
}
