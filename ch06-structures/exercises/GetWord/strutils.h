#ifndef STRUTILS_H
#define STRUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

/**
 * @brief Get next word or character from input.
*/
int getword(char* word, int lim);

/**
 * @brief Skips whitespace characters read from the input.
*/
void skipws(void);

/**
 * @brief Skips everything included in a comment.
*/
void skipcomment(void);

/**
 * @brief Skips everything included in a string constant.
*/
void skipstring(void);

/**
  * @brief Read the next char from stdin without removing it from the buffer.
*/
int peekch(void);

/**
  * @brief Read the next char from stdin.
*/
int getch(void);

/**
  * @brief Unread the given char, pushing it back onto the input buffer.
*/
bool ungetch(int);

/**
  * @brief Unread the given string, pushing it back onto the input buffer.
*/
void ungets(const char s[]);

/**
  * @brief Clear the input buffer. This function is only for testing purposes
  *   and should not really be used.
*/
void clearbuf(void);

#ifdef __cplusplus
}
#endif

#endif // STRUTILS_H
