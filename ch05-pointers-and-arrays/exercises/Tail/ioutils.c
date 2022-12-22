#include "ioutils.h"

#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readlines(char* * const lines, const int nlines, int (*getc)(void)) {
  char* line = NULL;
  int i = 0;
  while (strlen(line = readline(getc)) > 0) {
    if (i == nlines) {
      // free the first string
      free(*lines);
      // move everything back one index
      for (int j = 0; j < nlines - 1; j++) lines[j] = lines[j + 1];
      i = nlines - 1;
    }

    lines[i++] = line;
  }

  return i;
}

static const int DEFAULT_SIZE = 8;

char *readline(int (*getc)(void)) {
  char* line = NULL;
  int size = DEFAULT_SIZE;
  assert((line = malloc(size * sizeof(char))) != NULL);
  
  int nread = 0;
  int c;
  while ((c = getc()) != EOF && c != '\0') {
    if (nread == size - 1) { // can't fit, so we need to reallocate
      // Get a bigger chunk of memory for a new string
      char* tmp = malloc((size *= 2) * sizeof(char));
      assert(tmp != NULL);

      // Copy everything from line to tmp
      for (int i = 0; i < nread; i++) tmp[i] = line[i];
      free(line);
      line = tmp;
    }

    line[nread++] = c;
    if (c == '\n') break;
  }

  // Add terminating character
  line[nread] = '\0';

  return line;
}
