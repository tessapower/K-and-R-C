#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "fileutils.h"

#define STDIN 0
#define STDOUT 1
#define STDERR 2

// Exercise 8-1: Rewrite the program cat from Chapter 7 using read, write, open
//  and close instead of their standard library equivalents.

int main(int argc, char** argv) {
  int fd;

  if (argc == 1) {
    filecopy(STDIN, STDOUT);
  } else {
    while (--argc > 0) {
      if ((fd = open(*++argv, O_RDONLY, 0)) == 0) {
        write(STDERR, "Error opening file\n", 20);

        exit(1);
      } else {
        filecopy(fd, STDOUT);
        close(fd);
      }
    }
  }

  if (ferror(stdout)) {
    write(STDERR, "Error writing stdout\n", 20);

    exit(2);
  }

  exit(0);
}
