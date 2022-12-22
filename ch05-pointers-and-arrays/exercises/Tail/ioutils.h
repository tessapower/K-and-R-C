#ifndef IOUTILS_H
#define IOUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#define DEFAULT 10
#define MAXLINES 16

/**
 * @brief Reads the given number of lines of input. Returns NULL if no lines
 *  were read.
*/
int readlines(char** lines, int nlines, int (*getc)(void));

/**
 * @brief Reads a line and returns a pointer to it.
*/
char *readline(int (*getc)(void));

#ifdef __cplusplus
}
#endif

#endif // IOUTILS_H
