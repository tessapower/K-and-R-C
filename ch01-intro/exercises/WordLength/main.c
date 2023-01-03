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
    // Spaces, newlines, and tabs indicate the end of a word
    if (c == ' ' || c == '\n' || c == '\t') {
      if (wordlength >= MAX_LEN) {
        // Count words that are MAX_LEN or longer with MAX_LEN - 1 words
        ++wordlengths[MAX_LEN - 1];
      } else {
        ++wordlengths[wordlength];
      }
      wordlength = 0;
    } else {
      ++wordlength;
    }
  }

  // Print histogram
  for (int i = 1; i < MAX_LEN; ++i) {
    printf(" %*d", 2, i);

    if (i < MAX_LEN - 1) {
      printf("  |");
    } else {
      printf("+ |");
    }
     // Ignore zero length words
    if (wordlengths[i] > 0) {
      // Use the character '0' to create the histogram bar with correct length
      printf("%0*d\n", wordlengths[i], 0);
    } else {
      printf("\n");
    }
  }

  return 0;
}
