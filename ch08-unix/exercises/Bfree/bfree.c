#include "bfree.h"

#include <stdio.h>
#include <malloc.h>

// Exercise 8-8: Write a routine bfree(p, n) that will free an arbitrary block
//  p of n characters into the free list maintained by malloc and free. By using
//  bfree, a user can add a static or external array to the free list at any
//  time.

#define MAXSIZE 102400 // (Arbitrary) max size of a block

static Header base; // Empty list to get started
static Header* freep = NULL; // Start of free list

void* bettermalloc(unsigned nbytes) {
  Header* p, *prevp;
  unsigned nunits;

  // Check for valid size
  if (nbytes == 0 || nbytes > MAXSIZE) {
    fprintf(stderr, "Error: Invalid size for malloc");
    return NULL;
  }

  nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;
  if ((prevp = freep) == NULL) { // No free list yet
    base.s.next = freep = prevp = &base;
    base.s.size = 0;
  }

  for (p = prevp->s.next; ; prevp = p, p = p->s.next) {
    if (p->s.size >= nunits) { // Big enough
      if (p->s.size == nunits) { // Exactly
        prevp->s.next = p->s.next;
      } else { // Allocate tail end
        p->s.size -= nunits;
        p += p->s.size;
        p->s.size = nunits;
      }

      freep = prevp;

      return (void*)(p + 1);
    }

    if (p == freep) { // Wrapped around free list
      if ((p = morecore(nunits)) == NULL) {
        return NULL; // None left
      }
    }
  }
}

static unsigned largest = 0; // Largest assigned block

void betterfree(void* ap) {
  Header *bp, *p;

  if (ap == NULL) {
    fprintf(stderr, "Error: Invalid pointer for free");

    return;
  }

  if (largest < ((Header*)ap - 1)->s.size) {
    fprintf(stderr, "Error: Not a valid size block for free");
  }

  bp = (Header*)ap - 1; // Point to block header
  for (p = freep; !(bp > p && bp < p->s.next); p = p->s.next) {
    if (p >= p->s.next && (bp > p || bp < p->s.next)) {
      break; // Freed block at start or end of arena
    }
  }

  if (bp + bp->s.size == p->s.next) { // Join to upper nbr
    bp->s.size += p->s.next->s.size;
    bp->s.next = p->s.next->s.next;
  } else {
    bp->s.next = p->s.next;
  }

  if (p + p->s.size == bp) { // Join to lower nbr
    p->s.size += bp->s.size;
    p->s.next = bp->s.next;
  } else {
    p->s.next = bp;
  }


  freep = p;
}

#define NALLOC 1024 // minimum #units to request

static Header* morecore(unsigned nu) {
  char* cp;
  Header* up;

  if (nu < NALLOC) nu = NALLOC;

  cp = sbrk(nu * sizeof(Header));

  // Return null if no space at all
  if (cp == (char*)-1) return NULL;

  up = (Header*)cp;
  up->s.size = nu;
  if (up->s.size > largest) largest = up->s.size;

  betterfree((void*)(up + 1));

  return freep;
}

void bfree(void* p, unsigned n) {
  // Check if the size is large enough to be useful but smaller than the max
  if (n < sizeof(Header) || n > MAXSIZE) {
    fprintf(stderr, "Error: Invalid size for bfree");

    return;
  }

  // Add the block to the free list
  Header* bp = (Header*)p;
  bp->s.size = n / sizeof(Header);
  betterfree(bp);
}
