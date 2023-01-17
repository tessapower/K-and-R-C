#ifndef IOUTILS_H
#define IOUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdio.h>

struct Word {
  char* word;
  struct Line* lines;
  struct Word* left;
  struct Word* right;
};

struct Line {
  int number;
  struct Line* next;
};

typedef struct Word* WordTree;
typedef struct Line* LinesList;

/**
 * @brief Creates a WordTree from the given input lines.
 */
WordTree wordtree(const char** inputlines, const int numlines);

/**
 * @brief Allocates enough memory for a new Word.
 */
static struct Word* wordalloc(void);

/**
 * @brief Allocates enough memory for a new Line.
 */
static struct Line* linealloc(void);

/**
 * @brief Adds a word starting with the given node in a WordTree. Words are not
 *  case sensitive.
 */
static WordTree addword(struct Word* treenode, char* w, int linenum);

/**
 * @brief Adds a line number starting with the given node in a LinesList.
 */
static LinesList addline(struct Line* line, int linenum);

/**
 * @brief Prints the given WordTree in alphabetical order with the line number
 *  where each Word occurs.
*/
void printwordtree(WordTree root);

/**
 * @brief Prints the given LinesList.
*/
static void printlines(LinesList lines);

/**
 * @brief Frees the memory allocated for the given WordTree.
*/
void freewordtree(WordTree root);

/**
 * @brief Frees the memory allocated for the given LinesList.
*/
static void freelines(LinesList lines);

/**
 * @brief Processes a line of words, inserting or updating the found words in
 *  the WordTree.
*/
WordTree processline(const char* line, int linenum, WordTree root);

/**
 * @brief Get next word or character from the given line. Returns EOF when the
 *  end of the string has been reached.
*/
int nextword(char* word, int lim);

/**
 * @brief Returns whether the given char indicates the end of a line or file.
*/
static bool endofline(int c);

/**
 * @brief Returns whether the given word is a noise word.
*/
static bool isnoiseword(char* word);

#ifdef __cplusplus
}
#endif

#endif // IOUTILS_H
