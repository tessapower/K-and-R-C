#ifndef GETFLOAT_H
#define GETFLOAT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

// Exercise 5-2: Write getfloat, the floating-point analog of getint.

/**
 * @brief Get the next float from input into *pn. Returns zero if there is no
 *  valid integer on the input, EOF if the end of input was reached, or a
 *  positive value on success.
*/
int getfloat(float* pn);

static void skipws(void);
static bool isnum(int);
static bool issign(int c);
static bool isdecpoint(int c);

#ifdef __cplusplus
}
#endif

#endif // GETFLOAT_H
