#ifndef SORT_H
#define SORT_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Sort the given lines using the given comparison function.
*/
void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
void swap(void *v[], int i, int j);

#ifdef __cplusplus
}
#endif

#endif // SORT_H