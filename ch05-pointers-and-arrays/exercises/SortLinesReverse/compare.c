#include "compare.h"
#include <stdlib.h>

int numcmp(const char *lhs, const char *rhs) {
  double v1 = atof(lhs);
  double v2 = atof(rhs);

  if (v1 < v2) return -1;
  if (v1 > v2) return 1;

  // They are equal
  return 0;
}
