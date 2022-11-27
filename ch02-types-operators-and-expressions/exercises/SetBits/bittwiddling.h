#pragma once

/**
 * @brief Returns x with the n bits that begin at position p set to the rightmost n
 * bits of y, leaving the other bits unchanged.
*/
unsigned setbits(unsigned x, const unsigned p, const unsigned n, unsigned y);

/**
 * @brief Returns the n lower bits of x.
*/
unsigned getlowerbits(const unsigned x, const unsigned n);
