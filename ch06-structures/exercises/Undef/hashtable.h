#ifndef HASHTABLE_H
#define HASHTABLE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

// Table entry
struct nlist {
  // Next entry in the chain
  struct nlist* next;
  // Defined name
  char* name;
  // Replacement text
  char* defn;
};

/**
 * @brief Form hash value for string s.
*/
unsigned hash(char* s);

/**
 * @brief Look for s in the hashtable.
*/
struct nlist* lookup(char* s);

/**
 * @brief Put (name, defn) in the hashtable.
*/
struct nlist* install(char* name, char* defn);

/**
 * @brief Remove the definition associated with name from the hashtable,
 *  if it exists. Returns true if name was successfully removed, and false
 *  otherwise.
*/
bool undef(char* name);

/**
 * @brief Remove the entries from the hashtable.
*/
void cleartable(void);

/**
 * @brief Release the memory for the given list.
*/
static void freelist(struct nlist* np);

/**
 * @brief Release the memory for the given entry.
*/
static void freeentry(struct nlist* np);

#ifdef __cplusplus
}
#endif

#endif // HASHTABLE_H
