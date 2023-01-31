#ifndef FILEUTILS_H
#define FILEUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Print the size and inode information for the given file.
*/
void fsize(char* name);

/**
 * @brief Walk the given directory and call the given function for each file.
*/
void dirwalk(char* dir, void (*fcn)(char*));

#ifdef __cplusplus
}
#endif

#endif // FILEUTILS_H
