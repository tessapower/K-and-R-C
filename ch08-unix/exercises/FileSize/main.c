#include <stdio.h>

#include "fileutils.h"

// Exercise 8-5: Modify the fsize program to print the other information
//  contained in the inode entry.

int main(int argc, char* argv[]) {
  // Default to current directory if no arguments
  if (argc == 1) fsize(".");
  else while (--argc > 0) fsize(*++argv);

  return 0;
}
