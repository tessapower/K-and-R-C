#ifndef STRUTILS_H
#define STRUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Copy the first n characters from t to s; s must be big enough
*/
void strncopy(char *s, char *t, int n);

/**
 * @brief Concatenate the first n characters of t onto the end of s; s must be
 *   big enough
*/
void strnconcat(char* s, char* t, int n);

/**
 * @brief Compare the first n characters of s and t lexicographically;
 *   returns a negative number if s < t, zero if s == t, or a positive number 
 *   if s > t.
*/
int strncomp(char* s, char* t, int n);

#ifdef __cplusplus
}
#endif

#endif // STRUTILS_H
