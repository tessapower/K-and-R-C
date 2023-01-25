
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "hashtable.h"
#include "ioutils.h"

// Exercise 6-6: Implement a simple version of the #define processor (i.e. no
//  arguments) suitable for use with C programs, based on the routines of this
//  section. You may find getch and ungetch useful.

#define MAXLINE 1024
#define DEFINE "#define"
#define UNDEF "#undef"

int main() {
  char s[MAXLINE];
  struct nlist* replace = NULL;
  int c = 0;

  while ((c = getword(s, MAXLINE)) != EOF) {
    if (isalpha(c) || c == '_') {
      printf("%s", ((replace = lookup(s)) != NULL ? replace->defn : s));
    } else if (strcmp(DEFINE, s) == 0) {
      // Get name for the hashtable entry
      getname(s, MAXLINE);

      // Get the definiton
      char def[MAXLINE];
      getdef(def, MAXLINE);

      // Create/find entry and install or replace definition
      install(s, def);
    } else if (strcmp(UNDEF, s) == 0) {
      getname(s, MAXLINE);
      undef(s);
    } else {
      printf("%s", s);
    }
  }

  // clear hashtable
  cleartable();

  return 0;
}
