#ifndef BIT_TWIDDLING_H
#define BIT_TWIDDLING_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Returns x rotated to the right by n bits.
 */
unsigned rightrot(unsigned x, unsigned n);

/**
 * @brief Returns the n lower bits of x.
*/
unsigned getlowerbits(const unsigned x, const unsigned n);

#ifdef __cplusplus
}
#endif

#endif // BIT_TWIDDLING_H
