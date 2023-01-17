#include "ioutils.h"

#include <ctype.h>
#include <malloc.h>
#include <string.h>

WordTree wordtree(const char** inputlines, const int numlines) {
  // Return early if there are no lines to process
  if (inputlines == NULL || numlines < 1) return NULL;

  WordTree root = NULL;
  
  int linenum = 0;
  for (int i = 0; i < numlines; ++i, ++inputlines) {
    if (strlen(*inputlines) > 0) {
      root = processline(*inputlines, ++linenum, root);
    }
  }

  return root;
}

void printwordtree(const WordTree root) {
  if (root != NULL) {
    printwordtree(root->left);

    printf("\"%s\": ", root->word);
    printlines(root->lines);
    printf("\n");

    printwordtree(root->right);
  }
}

void printlines(LinesList lines) {
  while (lines != NULL) {
    printf("%d ", lines->number);
    lines = lines->next;
  }
}

void freewordtree(WordTree root) {
  if (root != NULL) {
    freewordtree(root->left);

    freewordtree(root->right);

    freelines(root->lines);
    free(root);
  }
}

void freelines(LinesList lines) {
  if (lines->next != NULL) freelines(lines->next);

  if (lines != NULL) free(lines);
}

struct Word* wordalloc(void) {
  return (struct Word*) malloc(sizeof(struct Word));
}

struct Line* linealloc(void) {
  return (struct Line*) malloc(sizeof(struct Line));
}

WordTree addword(struct Word* treenode, char* w, int linenum) {
  int cond;

  if (treenode == NULL) { // new word
    treenode = wordalloc();
    treenode->word = _strdup(w);

    struct Line* l = NULL;
    treenode->lines = addline(l, linenum);
    treenode->left = treenode->right = NULL;
  } else if ((cond = _stricmp(w, treenode->word)) == 0) { // same as this word
    treenode->lines = addline(treenode->lines, linenum);
  } else if (cond < 0) {
    treenode->left = addword(treenode->left, w, linenum);
  } else {
    treenode->right = addword(treenode->right, w, linenum);
  }

  return treenode;
}

LinesList addline(LinesList list, int linenum) {
  if (list != NULL) {
    if (list->number != linenum) list->next = addline(list->next, linenum);
  } else { // no previous line numbers
    list = linealloc();
    list->number = linenum;
    list->next = NULL;
  }

  return list;
}

static const char* lp = NULL;

#define MAXWORD 100

WordTree processline(const char* line, int linenum, WordTree root) {
  if (lp == NULL) lp = line;

  char word[MAXWORD];
  int res;
  while ((res = nextword(word, MAXWORD)) != EOF && res != -1) {
    if (word != NULL && !isnoiseword(word)) {
      root = addword(root, word, linenum);
    }
  }

  return root;
}

int nextword(char* word, int lim) {
  // if lp hasn't been set, return error code
  if (lp == NULL) return -1;

  char* w = word;

  // Skip any non-alphabetic characters
  while (!isalpha(*lp)) {
    // If we've reached the end of the string, stop processing & reset pointer
    if (endofline(*lp)) {
      lp = NULL;
      *w = '\0';

      return EOF;
    }

    lp++;
  }

  // If we reach here we're dealing with a word, so collect characters
  while (--lim > 0 && !(isspace(*lp))) {
    // We might find the end of the string while processing this word
    if (endofline(*lp)) {
      lp = NULL;

      break;
    }

    *w++ = *lp++;
  }

  *(w++) = '\0';

  return word[0];
}

bool endofline(int c) {
  return c == '\0' || c == EOF;
}

#define NUM_NOISE 22
static char* noisewords[NUM_NOISE] = {
  "a",
  "and",
  "at",
  "am",
  "an",
  "as",
  "at",
  "i",
  "i'm"
  "i've",
  "in",
  "if",
  "is",
  "it",
  "me",
  "my",
  "of",
  "on",
  "or",
  "so",
  "the",
  "to",
  "in"
};

bool isnoiseword(char* word) {
  for (int i = 0; i < NUM_NOISE; i++) {
    if (_stricmp(word, noisewords[i]) == 0)
      return true;
  }

  return false;
}
