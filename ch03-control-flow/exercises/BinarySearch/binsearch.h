#ifndef BINSEARCH_H
#define BINSEARCH_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Returns the index of x in v, or -1 if x is not found.
 */
int binsearch1(int x, int v[], int n);

/**
 * @brief Returns the index of x in v, or -1 if x is not found.
*/
int binsearch2(int x, int v[], int n);

#ifdef __cplusplus
}
#endif

#endif // BINSEARCH_H
