#ifndef STRUTILS_H
#define STRUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Converts characters like newline and tab into visible escape
 *   sequences like \n and \t as it copies the string t to s.
*/
void escape(char s[], char t[]);

/**
 * @brief Converts escape sequences into the real characters as it
 *  copies t to s.
*/
void unescape(char s[], char t[]);

#ifdef __cplusplus
}
#endif

#endif // STRUTILS_H
