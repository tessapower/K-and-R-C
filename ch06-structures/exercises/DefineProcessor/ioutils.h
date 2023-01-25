#ifndef IOUTILS_H
#define IOUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Returns the next word or character from the input.
*/
int getword(char* word, int lim);

/**
 * @brief Collects the name for a #define or #undef directive.
*/
void getname(char* name, int lim);

/**
 * @brief Collects the definition for a #define directive.
*/
void getdef(char* def, int lim);

/**
 * @brief Skips over whitespace characters.
*/
void skipws(void);

/**
 * @brief Prints an error messages and exits the program.
*/
void error(char* msg);

/**
  * @brief Read the next char from stdin without removing it from the buffer.
*/
static int peekch(void);

/**
  * @brief Read the next char from stdin.
*/
static int getch(void);

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

#endif // IOUTILS_H
