#include "binsearch.h"

// Exercise 3-1: Our binary search makes two tests inside the loop, when one
//  would suffice (at the price of more tests outside). Write a version with
//  only one test inside the loop and measure the difference in runtime.
//

int binsearch1(int x, int v[], int n) {
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;

    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else
      return mid;
  }

  return -1;
}

int binsearch2(int x, int v[], int n) {
  int low = 0;
  int high = n - 1;
  int mid = 0;

  while (low <= high && x != v[mid]) {
    mid = (low + high) / 2;

    if (x < v[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }

  return (v[mid] == x) ? mid : - 1;
}
