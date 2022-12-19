#include "strend.h"

#include <string.h>

// Exercise 5-4: Write the function strend(s, t), which returns 1 if the string
//  t occurs at the end of the string s, and 0 otherwise.

int strend(const char* s, const char* t) {
  // t cannot occur at the end of s because s is shorter than t
  if (strlen(s) < strlen(t)) return 0;

  int startidx = strlen(s) - strlen(t);
  s += startidx;

  return strcmp(s, t) == 0 ? 1 : 0;
}


