#ifndef STRUTILS_H
#define STRUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

/**
 * Deletes any character from todelete found in s.
*/
void squeeze(char s[], const char todelete[]);

/**
 * Returns the index of the first occurrence of c, or -1 if not found.
*/
bool contains(const char s[], const int c);

#ifdef __cplusplus
}
#endif

#endif // STRUTILS_H
