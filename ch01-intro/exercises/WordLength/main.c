#include <stdio.h>

#define MAX_LEN 10

// Exercise 1-13: Write a program to print a histogram of lengths of words in
//  its input.
int main() {
  int wordlengths[MAX_LEN];
  for (int i = 0; i < MAX_LEN; ++i) {
    wordlengths[i] = 0;
  }

  int c;
  int wordlength = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (wordlength >= MAX_LEN) {
        ++wordlengths[MAX_LEN - 1];
      } else {
        ++wordlengths[wordlength];
      }
      wordlength = 0;
    } else {
      ++wordlength;
    }
  }

  // Print histogram, ignore zero length words
  for (int i = 1; i < MAX_LEN; ++i) {
    printf(" %*d", 2, i);

    if (i < MAX_LEN - 1) {
      printf("  |");
    } else {
      printf("+ |");
    }

    if (wordlengths[i] > 0) {
      printf("%0*d\n", wordlengths[i], 0);
    } else {
      printf("\n");
    }
  }

  return 0;
}
