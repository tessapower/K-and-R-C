#include "ioutils.h"

#include <ctype.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>

WordCount wordcount(const char** inputlines, const int numlines) {
  // Return early if there are no lines to process
  if (inputlines == NULL || numlines < 1) return NULL;

  WordCount count = NULL;

  for (int i = 0; i < numlines; ++i, ++inputlines) {
    if (strlen(*inputlines) > 0) {
      count = processline(*inputlines, count);
    }
  }

  return count;
}

void printlist(WordCount list) {
  if (list->next != NULL) printlist(list->next);

  printf("%2d %s\n", list->count, list->word);
}

struct Word* wordalloc(void) {
  return (struct Word*)malloc(sizeof(struct Word));
}

WordCount insertword(WordCount list, char* w) {
  if (list == NULL) { // No words yet
    list = wordalloc();
    initword(list, w, NULL);
  } else {
    WordCount curr = list;
    while (curr != NULL) {
      if (_stricmp(w, curr->word) == 0) {
        curr->count++;

        // sort list
        list = sort(list);
        
        return list;
      }

      curr = curr->next;
    }

    // This word isn't in the list, so add a new one at the front
    WordCount front = wordalloc();
    initword(front, w, list);
    list = front;
  }

  return list;
}

void initword(struct Word* word, char* w, struct Word* next) {
  word->word = _strdup(w);
  word->count = 1;
  word->next = next;
}

WordCount sort(WordCount list) {
  struct Word* curr = list;
  struct Word* prev = NULL;

  while (curr->next != NULL) {
    if (curr->count > curr->next->count) {
      // swap current node with the next node
      struct Word* next = curr->next;
      curr->next = next->next;
      next->next = curr;

      if (prev == NULL) {
        list = next;
      } else {
        prev->next = next;
      }

      // Set curr to point to node at original position in the list
      curr = next;
    }

    prev = curr;
    curr = curr->next;
  }

  return list;
}

void freelist(WordCount list) {
  if (list->next != NULL) freelist(list->next);
  
  list->next = NULL;
  free(list);
}

static const char* lp = NULL;

#define MAXWORD 100

WordCount processline(const char* line, WordCount list) {
  if (lp == NULL) lp = line;

  char word[MAXWORD];
  int res;
  while ((res = nextword(word, MAXWORD)) != EOF && res != -1) {
    if (word != NULL) {
      list = insertword(list, word);
    }
  }

  return list;
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
