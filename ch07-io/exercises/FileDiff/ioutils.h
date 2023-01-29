#ifndef IOUTILS_H
#define IOUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

/**
 * Read a line from a file, return the length of the line or NULL if EOF.
*/
int getlinef(FILE* file, char* line, int max);

/**
 * Pretty print the difference between two lines.
*/
void prettyprintdiff(char* l1, char* l2);

#ifdef __cplusplus
}
#endif

#endif // IOUTILS_H
