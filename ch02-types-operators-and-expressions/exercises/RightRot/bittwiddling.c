#include "bittwiddling.h"
#include <limits.h>

// Exercise 2-8: Write a function rightrot(x, n) that returns the value of
//  integer x rotated to the right by n bit positions.

unsigned rightrot(unsigned x, unsigned n) {
  unsigned nbits = sizeof(x) * CHAR_BIT;
  n %= nbits;

  if (n == 0) return x;
  
  unsigned mask = getlowerbits(x, n) << (nbits - n);

  return (x >> n) | mask;
}

unsigned getlowerbits(const unsigned x, const unsigned n) {
  return x & ~(~(unsigned)0 << n);
}
