#include <limits.h>
#include <stdio.h>

#include "strutils.h"

int main() {
  printf(" min = %i\n", INT_MIN);
  printf("-min = %i\n", -INT_MIN);
  printf("~min = %i\n", ~INT_MIN);

  char intmax[50];
  itoa2(INT_MAX, intmax);
  printf(" %i with itoa =  %s\n", INT_MAX, intmax);

  char intmin[50];
  itoa2(INT_MIN, intmin);
  printf("%i with itoa = %s\n", INT_MIN, intmin);

  return 0;
}
