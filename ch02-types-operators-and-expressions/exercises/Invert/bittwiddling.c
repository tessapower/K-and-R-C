#include <assert.h>
#include "bittwiddling.h"

// Exercise 2-7: Write a function invert(x, p, n) that returns x with the n
//  bits that begin at position p inverted, leaving the others unchanged.
unsigned invert(unsigned x, const unsigned p, const unsigned n) {
  assert(p + 1 - n >= 0);

  for (int i = p; i >= p + 1 - n && i >= 0; --i) {
    int mask = 1 << i;
    unsigned bit = x & mask;
    if (bit == 0) {
      x |= mask;
    } else {
      x &= ~bit;
    }
  }

  return x;
}
