#include "compare.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int numcmp(const char *lhs, const char *rhs) {
  double v1 = atof(lhs);
  double v2 = atof(rhs);

  if (v1 < v2) return -1;
  if (v1 > v2) return 1;

  // They are equal
  return 0;
}

int dstrcomp(const char *lhs, const char *rhs) {
  char left;
  char right;

  do {
    while (!isalnum(*lhs) && *lhs != ' ' && *lhs != '\0') lhs++;
    while (!isalnum(*rhs) && *rhs != ' ' && *rhs != '\0') rhs++;
    left = *lhs;
    lhs++;
    right = *rhs;
    rhs++;

    if (left == right && left == '\0') return 0;
  } while (*lhs == right);

  return left - right;
}

int idstrcomp(const char *lhs, const char *rhs) {
  char left;
  char right;

  do {
    while (!isalnum(*lhs) && *lhs != ' ' && *lhs != '\0') lhs++;
    while (!isalnum(*rhs) && *rhs != ' ' && *rhs != '\0') rhs++;
    left = tolower(*lhs);
    lhs++;
    right = tolower(*rhs);
    rhs++;

    if (left == right && left == '\0') return 0;
  } while (*lhs == right);

  return left - right;
}
