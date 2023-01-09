#ifndef BIT_TWIDDLING_H
#define BIT_TWIDDLING_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Inverts n bits of x starting from position p.
 */
unsigned invert(unsigned x, const unsigned p, const unsigned n);

#ifdef __cplusplus
}
#endif

#endif // BIT_TWIDDLING_H
