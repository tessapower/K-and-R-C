#include <stdio.h>
#include "strutils.h"

// Exercise 2-4: Write an alternate version of squeeze(s1, s2) that deletes
//  each character in s1 that matches any character in the string s2.
int main() {
  char lorem[] = "Lorem ipsum but without the vowels";
  char vowels[] = "aeiou";
  
  // do the things
  printf("%s\n", lorem);
  squeeze(lorem, vowels);
  printf("%s\n", lorem);

  return 0;
}
