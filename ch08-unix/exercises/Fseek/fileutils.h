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
int _fillbuffer(FILE* fp);

/**
 * @brief Flush output buffer.
*/
int _flushbuffer(int fd, FILE* fp);

/**
 * @brief Flush the output buffer to the file.
*/
int flushfile(FILE* fp);

/**
 * @brief Close a file. Returns 0 on success, EOF on failure.
*/
int closefile(FILE* fp);

/**
 * @brief Open a file and return a file pointer.
*/
FILE* openfile(const char* path, const char* mode);

/**
 * @brief Set the file position indicator for the stream pointed to by fp.
 *  Returns 0 on success, -1 on failure.
*/
int fileseek(FILE* fp, long offset, int origin);

#define feof(p) (((p)->flags._EOF) != 0)
#define ferror(p) (((p)->flags._ERR) != 0)
#define fileno(p) ((p)->fd)

#define getc(p) (--(p)->cnt >= 0 ? (unsigned char) *(p)->ptr++ : _fillbuffer(p))
#define putc(c, p) (--(p)->cnt >= 0 ? *(p)->ptr++ = (x) : _flushbuffer((c), p))

#define getchar() getc(stdin)
#define putchar(c) putc((c), stdout)

#ifdef __cplusplus
}
#endif

#endif // FILEUTILS_H
