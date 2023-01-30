#ifndef FILEUTILS_H
#define FILEUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#define OPEN_MAX 20 // max #files open at once

typedef struct _iobuf {
  int cnt;    // characters left
  char* ptr;  // next character position
  char* base; // location of buffer
  int flag;   // mode of file access
  int fd;     // file descriptor
} FILE;

extern FILE _iob[OPEN_MAX];

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

enum _flags {
  _READ = 01,   // file open for reading
  _WRITE = 02,  // file open for writing
  _UNBUF = 04,  // file is unbuffered
  _EOF = 010,   // EOF has occurred on this file
  _ERR = 020    // error occurred on this file
};

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
