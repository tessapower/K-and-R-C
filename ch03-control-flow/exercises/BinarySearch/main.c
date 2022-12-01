#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <profileapi.h>

#include "binsearch.h"

#define NUM_TESTS 100000

LONGLONG exectime(int (*search)(int x, int v[], int n));

int main() {
  LONGLONG oldavgtime = exectime(binsearch1);
  LONGLONG newavgtime = exectime(binsearch2);

  printf("Old binary search: %lli\n", oldavgtime);
  printf("New binary search: %lli\n", newavgtime);

  return 0;
}

LONGLONG exectime(int (*search)(int x, int v[], int n)) {
  int nums[NUM_TESTS];
  for (int i = 0; i < NUM_TESTS; i++) {
    nums[i] = i;
  }

  LARGE_INTEGER start, end;
  LARGE_INTEGER freq;

  QueryPerformanceFrequency(&freq);
  QueryPerformanceCounter(&start);

  for (int i = 0; i < NUM_TESTS; i++) {
    search(i, nums, NUM_TESTS);
  }

  QueryPerformanceCounter(&end);

  return end.QuadPart - start.QuadPart;
}
