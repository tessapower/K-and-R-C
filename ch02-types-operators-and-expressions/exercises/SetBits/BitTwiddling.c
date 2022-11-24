#include "BitTwiddling.h"
#include <assert.h>

// Exercise 2-6: Write a function setbits(x, p, n, y) that returns x with the
//  n bits that begin at position p set to the rightmost n bits of y, 
//  the other bits unchanged.
unsigned setBits(unsigned x, const unsigned p, const unsigned n, unsigned y) {
  assert(p + 1 - n >= 0);
  // Set n bits at pos p to 0
  // Create mask for n bits
  unsigned zeroMask = ~(~(unsigned)0 << n);
  // Shift to coincide with pos p of x and negate so we turn off only n bits
  zeroMask = ~(zeroMask << (p + 1 - n));

  x = x & zeroMask;

  // Create a mask of y
  unsigned bitMask = getLowerBits(y, n);
  // Shift to coincide with pos p of x
  bitMask = bitMask << (p + 1 - n);

  // Set n bits at pos p to the n rightmost bits of y
  return x | bitMask;
}

unsigned getLowerBits(const unsigned x, const unsigned n) {
  return x & ~(~(unsigned)0 << n);
}
