#include "sort.h"

void qsort(void *v[], const int left, const int right,
  int (*comp)(void *, void *)) {
  // Do nothing if array contains fewer than two elements
  if (left >= right) return;

  swap(v, left, (left + right) / 2);
  int last = left;
  
  for (int i = left + 1; i <= right; ++i) {
    if ((*comp)(v[i], v[left]) <= 0) swap(v, ++last, i);
  }

  swap(v, left, last);
  qsort(v, left, last - 1, comp);
  qsort(v, last + 1, right, comp);
}

void swap(void* v[], const int i, const int j) {
  void *temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
