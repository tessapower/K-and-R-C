#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "fileutils.h"

// Exercise 8-3: Design and write _flushbuf, fflush, and fclose.

FILE _iob[OPEN_MAX] = { // stdin, stdout, stderr
  {0, (char*)0, (char*)0, {1, 0, 0, 0, 0}, 0}, // Open for reading
  {0, (char*)0, (char*)0, {0, 1, 0, 0, 0}, 1}, // Open for writing
  {0, (char*)0, (char*)0, {0, 1, 1, 0, 0}, 2}  // Open for writing, unbuffered
};

#define PERMS 0666 // RW for owner, group, others

FILE *openfile(const char* name, const char* mode) {
  int fd;
  FILE *fp;

  if (*mode != 'r' && *mode != 'w' && *mode != 'a') {
    return NULL;
  }

  for (fp = _iob; fp < _iob + OPEN_MAX; fp++) {
    if (fp->flags._READ == 0 | fp->flags._WRITE == 0) break; // Found free slot
  }

  if (fp >= _iob + OPEN_MAX) return NULL; // No free slots

  if (*mode == 'w') {
    fd = creat(name, PERMS);
  } else if (*mode == 'a') {
    if ((fd = open(name, O_WRONLY, 0)) == -1) fd = creat(name, PERMS);
    lseek(fd, 0L, 2);
  } else {
    fd = open(name, O_RDONLY, 0);
  }

  if (fd == -1) return NULL; // Couldn't access name

  fp->fd = fd;
  fp->cnt = 0;
  fp->base = NULL;

  // Set flags
  if (*mode == 'r') {
    fp->flags._READ = 1;
    fp->flags._WRITE = 0;
  } else {
    fp->flags._READ = 0;
    fp->flags._WRITE = 1;
  }

  fp->flags._UNBUF = 0;
  fp->flags._EOF = 0;
  fp->flags._ERR = 0;

  return fp;
}

int _fillbuffer(FILE* fp) {
  if (fp->flags._READ == 0 | fp->flags._EOF == 1 | fp->flags._ERR == 1) return EOF;

  int bufsize = (fp->flags._UNBUF) ? 1 : BUFSIZ;

  if (fp->base == NULL) { // No buffer yet
    if ((fp->base = (char*)malloc(bufsize)) == NULL) return EOF; // Can't get buffer
  }

  fp->ptr = fp->base;
  fp->cnt = read(fp->fd, fp->ptr, bufsize);

  if (--fp->cnt < 0) {
    if (fp->cnt == -1) fp->flags._EOF = 1;
    else fp->flags._ERR = 1;

    fp->cnt = 0;

    return EOF;
  }

  return (unsigned char) *fp->ptr++;
}

int _flushbuffer(int c, FILE* fp) {
  // Handle invalid file pointer
  if (fp < _iob || fp >= _iob + OPEN_MAX) return EOF;
  // Handle invalid file mode
  if (fp->flags._WRITE == 0 | fp->flags._ERR == 1) return EOF;

  int bufsize = (fp->flags._UNBUF) ? 1 : BUFSIZ;

  if (fp->base == NULL) { // No buffer yet
    // Check if buffer available
    if ((fp->base = (char*)malloc(bufsize)) == NULL) return EOF;
  } else {
    // Write buffer to file
    unsigned n = fp->ptr - fp->base;

    if (write(fp->fd, fp->base, n) != n) {
      // Couldn't write buffer to file
      fp->flags._ERR = 1;

      return EOF;
    }
  }

  // Reset pointer and count
  fp->ptr = fp->base;
  fp->cnt = bufsize - 1;
  *fp->ptr++ = (char) c;

  return c;
}

int flushfile(FILE* fp) {
  int res = 0;
  // Handle invalid file pointer
  if (fp < _iob || fp >= _iob + OPEN_MAX) return EOF;
  // Handle invalid file mode
  if (fp->flags._WRITE == 0 | fp->flags._ERR == 1) return EOF;

  // Flush buffer
  res = _flushbuffer(0, fp);

  // Reset pointer and count
  fp->ptr = fp->base;
  fp->cnt = (fp->flags._UNBUF) ? 1 : BUFSIZ;

  return res;
}

int closefile(FILE* fp) {
  int res;

  if ((res = flushfile(fp)) != EOF) {
    // Free space allocated for buffer
    free(fp->base);

    // Reset file information and buffer
    fp->base = NULL;
    fp->ptr = NULL;
    fp->cnt = 0;

    // Reset flags
    fp->flags._READ = 0;
    fp->flags._WRITE = 0;
    fp->flags._UNBUF = 0;
    fp->flags._EOF = 0;
    fp->flags._ERR = 0;
  }

  return res;
}
