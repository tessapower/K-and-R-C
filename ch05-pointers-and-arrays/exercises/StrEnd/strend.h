#ifndef STREND_H
#define STREND_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Returns 1 if the string t occurs at the end of the string s,
 *   or 0 otherwise.
*/
int strend(const char *s, const char *t);

#ifdef __cplusplus
}
#endif

#endif // STREND_H
