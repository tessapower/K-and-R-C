#ifndef CALLOC_H
#define CALLOC_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Allocates memory for an array of n objects of size s and initializes
 *  the memory to zero. Returns a pointer to the allocated memory.
 */
void* calloc(unsigned n, unsigned s);

#ifdef __cplusplus
}
#endif

#endif // CALLOC_H
