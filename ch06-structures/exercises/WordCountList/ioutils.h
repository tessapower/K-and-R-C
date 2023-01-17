#ifndef MINHEAP_H
#define MINHEAP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

struct Word {
  char* word;
  int count;
  struct Word* next;
};

typedef struct Word* WordCount;

/**
 * @brief Creates a WordCount list from the given input lines.
 */
WordCount wordcount(const char** inputlines, const int numlines);

/**
 * @brief Prints the given WordCount list in descending order.
*/
void printlist(WordCount list);

/**
 * @brief Allocates enough memory for a new Word.
 */
static struct Word* wordalloc(void);

/**
 * @brief Inserts a Word into the WordCount list. If the Word already exists,
 *  increases the count and, if necessary, moves the Word so that the list 
 *  remains sorted in ascending order. Words are not case sensitive.
*/
static WordCount insertword(WordCount list, char* w);

/**
 * @brief Initializes the given Word with the given string and next Word.
*/
static void initword(struct Word* word, char* w, struct Word* next);

/**
 * @brief Sorts the given WordCount list.
*/
static WordCount sort(WordCount list);

/**
 * @brief Frees the memory allocated for the given WordCount list.
*/
void freelist(WordCount list);

/**
 * @brief Processes a line of words, inserting or updating the found words in
 *  the WordCount list.
*/
WordCount processline(const char* line, WordCount list);

/**
 * @brief Get next word or character from the given line. Returns EOF when the
 *  end of the string has been reached.
*/
int nextword(char* word, int lim);

/**
 * @brief Returns whether the given char indicates the end of a line or file.
*/
static bool endofline(int c);

#ifdef __cplusplus
}
#endif

#endif // IOUTILS_H