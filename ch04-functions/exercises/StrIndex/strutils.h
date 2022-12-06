#ifndef STRUTILS_H
#define STRUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Returns the rightmost index of t in s, or -1 if there is none.
*/
int strrindex(const char s[], const char t[]);

#ifdef __cplusplus
}
#endif

#endif // STRUTILS_H
