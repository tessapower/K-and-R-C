#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int c;
  int nl, nw, nc;
  nl = nw = nc = 0;
  int state = OUT;

  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n') ++nl;
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }

  printf("%d %d %d\n", nl, nw, nc);

  return 0;
}
