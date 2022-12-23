#ifndef STRUTILS_H
#define STRUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#define MAXLEN 1000

/**
 * @brief Read strings using the given function into lineptr.
*/
int readlines(char *lineptr[], int maxlines, int (*getc)(void));

/**
 * @brief Read string into line using the given function, returns the length.
*/
static int getline(char* line, const int maxlen, int (*getc)(void));

/**
 * @brief Write the given lines to the stdout.
*/
void writelines(char* lineptr[], int nlines);

/**
 * @brief Returns a pointer to n characters.
*/
static char *alloc(int n);

/**
 * @brief Free storage pointer to by p
*/
static void afree(char* p);

#ifdef __cplusplus
}
#endif

#endif // STRUTILS_H