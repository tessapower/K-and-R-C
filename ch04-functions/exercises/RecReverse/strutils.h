#ifndef STRUTILS_H
#define STRUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Reverses the given string in place.
*/
void reverse(char s[]);

static void swap(char s[], size_t i, size_t j);

#ifdef __cplusplus
}
#endif

#endif // STRUTILS_H
