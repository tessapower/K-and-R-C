#ifndef BIT_TWIDDLING_H
#define BIT_TWIDDLING_H

#ifdef __cplusplus
extern "C" {
#endif
/**
 * @brief Returns x with the n bits that begin at position p set to the rightmost n
 * bits of y, leaving the other bits unchanged.
*/
unsigned setbits(unsigned x, const unsigned p, const unsigned n, unsigned y);

/**
 * @brief Returns the n lower bits of x.
*/
unsigned getlowerbits(const unsigned x, const unsigned n);

#ifdef __cplusplus
}
#endif

#endif // BIT_TWIDDLING_H
