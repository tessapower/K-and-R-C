#include <string.h>
#include "ioutils.h"

int getlinef(FILE* file, char* line, int max) {
  return (fgets(line, max, file) == NULL) ? 0 : strlen(line);
}

void prettyprintdiff(char* l1, char* l2) {
  int idx = 0;
  // Trim newline character
  int len1 = strlen(l1);
  int last = len1 - 1;
  if (l1[last] == '\n') {
    l1[last] = '\0';
  }

  int len2 = strlen(l2);
  last = len2 - 1;
  if (l2[last] == '\n') {
    l2[last] = '\0';
  }

  // Find the first character where they differ and note the index
  while (idx < len1 && idx < len2 && l1[idx] == l2[idx]) {
    idx++;
  }

  printf("\"%s\"\n", l1);

  // Visually indicate where the lines differ
  for (int i = 0; i <= idx; i++) {
    printf("-");
  }
  printf("^\n");

  printf("\"%s\"\n", l2);
}
