#include <stdio.h>
#include <limits.h>
#include <float.h>

// Exercise 2-1: Write a program to determine the ranges of char, short, int,
//  and long variables, both signed and unsigned, by printing appropriate
//  values from standard headers and by direct computation.
int main() {
  // char
  printf("unsigned char:\t%hhu to %hhu\n", 0, UCHAR_MAX);
  printf("  signed char:\t%hhi to %hhi\n", CHAR_MIN, CHAR_MAX);

  // short
  printf("unsigned short:\t%hu to %hu\n", 0, USHRT_MAX);
  printf("  signed short:\t%hi to %hi\n", SHRT_MIN, SHRT_MAX);

  // int
  printf("unsigned int:\t%u to %u\n", 0, UINT_MAX);
  printf("  signed int:\t%i to %i\n", INT_MIN, INT_MAX);

  // long
  printf("unsigned long:\t%lu to %lu\n", 0, ULONG_MAX);
  printf("  signed long:\t%li to %li\n", LONG_MIN, LONG_MAX);

  return 0;
}
