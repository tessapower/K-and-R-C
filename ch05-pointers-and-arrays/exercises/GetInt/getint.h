#ifndef GETINT_H
#define GETINT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

// Exercise 5-1: As written, getint treats a + or - not followed by a digit as
//  a valid representation of zero. Fix it to push such a character back on the
//  input.

/**
 * @brief Get the next integer from input into *pn
*/
int getint(int* pn);

static bool isnum(int);
static bool issigned(int c);

#ifdef __cplusplus
}
#endif

#endif // GETINT_H
