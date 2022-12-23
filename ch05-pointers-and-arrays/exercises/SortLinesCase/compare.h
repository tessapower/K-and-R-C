#ifndef COMPARE_H
#define COMPARE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

/**
 * @brief Compares two strings numerically, returns 0 if they are equal,
 *  1 if lhs > rhs, and -1 if lhs < rhs.
*/
int numcmp(const char *lhs, const char *rhs);

#ifdef __cplusplus
}
#endif

#endif // COMPARE_H
