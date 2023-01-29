#include <string.h>
#include "ioutils.h"

int getlinef(FILE* file, char* line, int max) {
  return (fgets(line, max, file) == NULL) ? 0 : strlen(line);
}
