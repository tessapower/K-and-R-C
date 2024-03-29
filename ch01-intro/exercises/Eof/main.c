#include <stdio.h>

// Exercise 1-6: Verify that the expression `getchar() != EOF` is 0 or 1.
int main() {
  int c;
  while (c = getchar() != EOF) {
    printf("c = %d != EOF\n", c);
  }
  printf("c = %d == EOF\n", c);

  return 0;
}
