#ifndef FILEUTILS_H
#define FILEUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Copy the contents of the file fdin to the file fdout.
*/
void filecopy(int fdin, int fdout);

#ifdef __cplusplus
}
#endif

#endif // FILEUTILS_H
