#include <stdio.h>
#include <unistd.h>

#include "fileutils.h"

void filecopy(int fdin, int fdout) {
  int n;
  char buf[BUFSIZ];

  while ((n = read(fdin, buf, BUFSIZ)) > 0) {
    int written = write(fdout, buf, n);

    if (written != n) {
      printf("Error writing to file\n");

      return;
    }
  }
}
