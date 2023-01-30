#ifndef FILEUTILS_H
#define FILEUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#define OPEN_MAX 20 // max #files open at once

struct Flags {
  unsigned int _READ  : 1; // file open for reading
  unsigned int _WRITE : 1; // file open for writing
  unsigned int _UNBUF : 1; // file is unbuffered
  unsigned int _EOF   : 1; // EOF has occurred on this file
  unsigned int _ERR   : 1; // error occurred on this file
};

typedef struct _iobuf {
  int cnt;            // characters left
  char* ptr;          // next character position
  char* base;         // location of buffer
  struct Flags flags; // mode of file access
  int fd;             // file descriptor
} FILE;

extern FILE _iob[OPEN_MAX];

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

/**
 * @brief Allocate and fill input buffer.
*/
int _fillbuf(FILE*);

/**
 * @brief Open a file and return a file pointer.
*/
FILE *openfile(const char* path, const char* mode);

#ifdef __cplusplus
extern }
#endif

#endif // FILEUTILS_H
