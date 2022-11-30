#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <profileapi.h>

#include "binsearch.h"

#define NUM_TESTS 150000

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

  LARGE_INTEGER start, end, elapsedms;
  LARGE_INTEGER freq;

  QueryPerformanceFrequency(&freq);
  QueryPerformanceCounter(&start);

  for (int i = 0; i < NUM_TESTS; i++) {
    search(i, nums, NUM_TESTS);
  }

  QueryPerformanceCounter(&end);

  return end.QuadPart - start.QuadPart;

  //elapsedms.QuadPart = end.QuadPart - start.QuadPart;

  //
  // We now have the elapsed number of ticks, along with the
  // number of ticks-per-second. We use these values
  // to convert to the number of elapsed microseconds.
  // To guard against loss-of-precision, we convert
  // to microseconds *before* dividing by ticks-per-second.
  //

  //elapsedms.QuadPart *= 1000000;
  //elapsedms.QuadPart /= freq.QuadPart;
}
