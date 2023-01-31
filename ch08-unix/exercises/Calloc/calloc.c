#include "calloc.h"

#include <stdio.h>

// Exercise 8-6: The standard library function calloc(n, size) returns a pointer
//  to n objects of size size, with the storage initialized to zero. Write
//  calloc, by calling malloc or by modifying it.

void* calloc(unsigned n, unsigned size) {
  void* p = malloc(n * size);
  if (p != NULL) {
    memset(p, 0, n * size);
  }

  return p;
}
