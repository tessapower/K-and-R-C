#include <stdio.h>

#define ALPHA 26
#define DIGIT 10

// Exercise 1-14: Write a program to print a histogram of the frequencies of
//  different characters on its input.
int main() {
  int space = 0;
  int tab = 0;
  int newline = 0;
  int unknown = 0;

  int digit[DIGIT];
  for (int i = 0; i < DIGIT; ++i) {
    digit[i] = 0;
  }

  int alpha[ALPHA];
  for (int i = 0; i < ALPHA; ++i) {
    alpha[i] = 0;
  }

  int c;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++space;
    } else if (c == '\n') {
      ++newline;
    } else if (c == '\t') {
      ++tab;
    } else if (c >= '0' && c <= '9') {
      ++digit[c - '0'];
    } else if (c >= 'A' && c <= 'Z') {
      ++alpha[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
      ++alpha[c - 'a'];
    } else {
      ++unknown;
    }
  }

  for (int i = 0; i < DIGIT; ++i) {
    printf(" %c |", '0' + i);

    if (digit[i] > 0) {
      printf("%0*d\n", digit[i], 0);
    } else {
      printf("\n");
    }
  }

  for (int i = 0; i < ALPHA; ++i) {
    printf(" %c |", 'A' + i);

    if (alpha[i] > 0) {
      printf("%0*d\n", alpha[i], 0);
    } else {
      printf("\n");
    }
  }

  printf("\\s |");
  if (space > 0) {
    printf("%0*d\n", space, 0);
  } else {
    printf("\n");
  }

  printf("\\t |");
  if (space > 0) {
    printf("%0*d\n", space, 0);
  } else {
    printf("\n");
  }

  printf("\\n |");
  if (space > 0) {
    printf("%0*d\n", space, 0);
  } else {
    printf("\n");
  }

  return 0;
}