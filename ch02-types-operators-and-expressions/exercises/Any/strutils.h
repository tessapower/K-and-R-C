#ifndef STRUTILS_H
#define STRUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Returns the index of the first occurrence of any character in s2 in
 * the string s1, or -1 if no characters in s2 are found in s1.
*/
int any(const char s1[], const char s2[]);

/**
 * @brief Returns the index of the first occurrence of c in s, or -1 if none.
*/
int findfirst(const char s[], const int c);

#ifdef __cplusplus
}
#endif

#endif // STRUTILS_H
