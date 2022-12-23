#include "sort.h"
#include "compare.h"

#include <stdlib.h>
#include <string.h>

void sort(void* v[], int size, int options) {
  bool caseinsensitive = options & CASE_INSENSITIVE;
  bool numeric = options & NUMERIC;
  bool reverse = options & REVERSE;
  quicksort(v, 0, size - 1, 
    (int (*)(void*, void*))(numeric
      ? numcmp
      : (caseinsensitive
        ? _stricmp
        : strcmp)),
    reverse);
}

void quicksort(void *v[], const int left, const int right,
  int (*comp)(void *, void *), bool reverse) {
  // Do nothing if array contains fewer than two elements
  if (left >= right) return;

  swap(v, left, (left + right) / 2);
  int last = left;
  
  for (int i = left + 1; i <= right; ++i) {
    if (reverse) {
      if ((*comp)(v[i], v[left]) > 0) swap(v, ++last, i);
    } else {
      if ((*comp)(v[i], v[left]) < 0) swap(v, ++last, i);
    }
  }

  swap(v, left, last);
  quicksort(v, left, last - 1, comp, reverse);
  quicksort(v, last + 1, right, comp, reverse);
}

void swap(void* v[], const int i, const int j) {
  void *temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
