#ifndef COMPARE_H
#define COMPARE_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Compares the two strings numerically, returns 0 if they are equal,
 * 1 if lhs > rhs, and -1 if lhs < rhs.
*/
int numcmp(const char *lhs, const char *rhs);

/**
 * @brief Compares the two strings lexicographically, disregarding any
 *  characters which are not letters, numbers, or spaces. Returns 0 if they are
*   equal, 1 if lhs > rhs, and -1 if lhs < rhs.
*/
int dstrcomp(const char *lhs, const char *rhs);

/**
 * @brief Compares the two strings lexicographically, disregarding case and any
 *  characters which are not letters, numbers, or spaces. Returns 0 if they are
*   equal, 1 if lhs > rhs, and -1 if lhs < rhs.
*/
int idstrcomp(const char *lhs, const char *rhs);

#ifdef __cplusplus
}
#endif

#endif // COMPARE_H
