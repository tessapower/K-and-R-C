#ifndef STRUTILS_H
#define STRUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Converts the given integer to to a string and places the result in s.
*/
void itostr(int n, char s[]);

#ifdef __cplusplus
}
#endif

#endif // STRUTILS_H
