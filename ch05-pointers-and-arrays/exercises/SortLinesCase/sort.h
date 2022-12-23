#ifndef SORT_H
#define SORT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#define REVERSE          0x1 << 1;
#define NUMERIC          0x1 << 2;
#define CASE_INSENSITIVE 0x1 << 3;

/**
 * @brief Sort the content of the array in numerical and/or reverse order.
*/
void sort(void* v[], int size, int options);

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