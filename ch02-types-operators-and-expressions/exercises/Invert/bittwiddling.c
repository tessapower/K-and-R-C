#include <assert.h>
#include "bittwiddling.h"

// Exercise 2-7: Write a function invert(x, p, n) that returns x with the n
//  bits that begin at position p inverted, leaving the others unchanged.

unsigned invert(unsigned x, const unsigned p, const unsigned n) {
  assert(p + 1 - n >= 0);

  return x ^ (~(~(unsigned)0 << n) << (p + 1 - n));
}
