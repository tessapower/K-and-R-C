#include <stdio.h>

#define MAX_LINE 1000
enum boolean { FALSE, TRUE };

int getline(char line[], const int lim);

// Exercise 2-2: Write a loop equivalent to the for loop below without using
//  && or ||:
//
//  int i;
//  for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
//    s[i] = c;
//  }
//
int main() {
  char s[MAX_LINE];

  while (getline(s, MAX_LINE) != 0)
    printf("You entered:\n\"%s\"\n", s);

  return 0;
}

int getline(char s[], const int lim) {
  int i = 0;
  enum boolean end = FALSE;
  while (!end) {
    if (i >= lim - 1) end = TRUE;
    else if (!end) {
      char c = getchar();
      if (c == '\n') end = TRUE;
      else if (c == EOF) end = TRUE;

      if (!end) s[i++] = c;
    }
  }
  
  s[i] = '\0';
  // If we never added anything to the string, don't increment the length
  i += (i > 0) ? 1 : 0;

  return i;
}
