#ifndef STRUTILS_H
#define STRUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Converts an integer to a string in the given base.
*/
void itob(int n, char s[], const int b);

/**
 * @brief Converts an integer to its string representation.
*/
void itostr(int n, char s[]);

/**
 * @brief Reverses a string in place.
*/
void reverse(char s[]);

#ifdef __cplusplus
}
#endif

#endif // STRUTILS_H
