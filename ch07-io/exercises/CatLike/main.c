#include <stdio.h>

// Exercise 7-8: Write a program to print a set of files, starting each new one
//  on a new page, with a title and a running page count for each file.

// Note: by "print a set of files", K&R meant literally print with a physical
// printer, not print to the screen. This program will print to the screen.

#define MAXLINE 256
#define LINES_PER_PAGE 80

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Usage: %s [FILE]...", argv[0]);

    return 1;
  }

  for (int i = 1; i < argc; ++i) {
    FILE* file;

    if ((file = fopen(argv[i], "r")) == NULL) {
      printf("Error: could not open file %s", argv[i]);
    }

    // Print file
    int page = 1;
    int linenum = 1;
    char line[MAXLINE];
    while ((fgets(line, MAXLINE, file)) != NULL) {
      // Print the header if we're on a new page
      if (linenum == 1) {
        printf("%s, page %i\n\n", argv[i], page);
        linenum += 2;
      }

      // Print the line
      printf("%s", line);

      // Reset if we're on a new page
      if (++linenum == LINES_PER_PAGE) {
        printf("\f");
        ++page;
        linenum = 1;
      }
    }
    // Make sure to print everything on the last page
    printf("\f");

    fclose(file);
  }


  return 0;
}
