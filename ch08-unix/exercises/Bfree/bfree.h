#ifndef BFREE_H
#define BFREE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef long Align; // for alignment to long boundary

union header { // block header
    struct {
        union header* next; // next block if on free list
        unsigned size; // size of this block
    } s;
    Align x; // force alignment of blocks
};

typedef union header Header;

/**
 * @brief General purpose memory allocator. Returns a pointer to n bytes of
 *  memory, or NULL if the request cannot be satisfied. The allocated memory
 *  is not initialized.
*/
void* bettermalloc(unsigned nbytes);

/**
 * @brief Put block ap in free list for later reuse.
*/
void betterfree(void* ap);

/**
 * @brief Asks the system for more memory.
*/
static Header* morecore(unsigned nu);

/**
 * @brief Free an arbitrary block p of n characters that was allocated by malloc
*/
void bfree(void* p, unsigned n);

#ifdef __cplusplus
}
#endif

#endif // BFREE_H

