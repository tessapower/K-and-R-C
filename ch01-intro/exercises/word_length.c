#include <stdio.h>

#define MAX_LEN 10

// Exercise 1-13: Write a program to print a histogram of lengths of words in
//  its input.
int main() {
  int wordLengths[MAX_LEN];
  for (int i = 0; i < MAX_LEN; ++i) {
    wordLengths[i] = 0;
  }

  int c;
  int wordLength = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (wordLength >= MAX_LEN) {
        ++wordLengths[MAX_LEN - 1];
      } else {
        ++wordLengths[wordLength];
      }
      wordLength = 0;
    } else {
      ++wordLength;
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

    if (wordLengths[i] > 0) {
      printf("%0*d\n", wordLengths[i], 0);
    } else {
      printf("\n");
    }
  }

  return 0;
}