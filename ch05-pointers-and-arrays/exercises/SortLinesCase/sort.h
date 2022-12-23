#ifndef SORT_H
#define SORT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

/**
 * @brief Sort the content of the array in numerical and/or reverse order.
*/
void sort(void* v[], int size, bool numeric, bool reverse);

/**
 * @brief Sort the given lines using the given comparison function.
*/
static void quicksort(void *lineptr[], int left, int right,
  int (*comp)(void *, void *), bool reverse);

void swap(void *v[], int i, int j);

#ifdef __cplusplus
}
#endif

#endif // SORT_H