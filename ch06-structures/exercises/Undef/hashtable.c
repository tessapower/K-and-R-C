#include "hashtable.h"

#include <malloc.h>
#include <stdio.h>
#include <string.h>

// Exercise 6-5: Write a function undef() that will remove a name and
//  definition from the table maintained by lookup() and install().

#define HASHSIZE 101

// Pointer table
static struct nlist* hashtab[HASHSIZE];

unsigned hash(char* s) {
  unsigned hashval = 0;

  while (*s != '\0') hashval = *(s++) + 31 * hashval;

  return hashval % HASHSIZE;
}

struct nlist* lookup(char* s) {
  struct nlist* np = hashtab[hash(s)];

  while (np != NULL) {
    if (strcmp(s, np->name) == 0) return np;
    np = np->next;
  }

  return NULL;
}

struct nlist* install(char* name, char* defn) {
  struct nlist* np = lookup(name);

  bool found = np != NULL;
  if (!found) {
    np = (struct nlist*) malloc(sizeof(*np));
    if (np == NULL || (np->name = _strdup(name)) == NULL) return NULL;

    unsigned hashval = 0;
    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  } else {
    // Entry already exists so free previous defn
    free((void*) np->defn);
  }

  if ((np->defn = _strdup(defn)) == NULL) return NULL;

  return np;
}

bool undef(char* name) {
  unsigned hashval = hash(name);
  struct nlist* np = hashtab[hashval];

  // Return early if there are no entries in this bucket
  if (np == NULL) return false;

  struct nlist* prev = NULL;
  while (np != NULL) {
    if (strcmp(name, np->name) == 0) {
      if (prev == NULL) { // Beginning of bucket
        hashtab[hashval] = np->next;
      } else {
        prev->next = np->next;
      }

      freeentry(np);

      return true;
    }

    prev = np;
    np = np->next;
  }

  // No entry found by the given name, i.e. no change
  return false;
}

void cleartable(void) {
  for (int i = 0; i < HASHSIZE; ++i) {
    struct nlist* np = hashtab[i];
    if (np != NULL) {
      freelist(np);
    }

    hashtab[i] = NULL;
  }
}

void freelist(struct nlist* np) {
  if (np->next != NULL) {
    freelist(np->next);
  }

  freeentry(np);
}

void freeentry(struct nlist* np) {
  np->next = NULL;
  free((void*) np->name);
  free((void*) np->defn);
  free((void*) np);
}
