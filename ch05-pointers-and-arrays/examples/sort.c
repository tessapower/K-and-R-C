//
// Created by Tessa Power on 22/09/21.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000       // max #lines to be sorted
#define MAXLEN 1000         // max length of any input lines
char *lines[MAXLINES];      // pointers to text lines
#define ALLOCSIZE 10000     // size of available space

static char allocbuf[ALLOCSIZE];    // storage for alloc
static char *allocp = allocbuf;     // next free position

int readLines(char *linePtr[], int maxLines);
int getLine(char *s, int lim);
char *alloc(int n);
void writeLines(char *linePtr[], int numLines);
void myQsort(void *v[], int left, int right, int (*comp)(const void *, const void *));
void swap(void *v[], int i, int j);
int numCmp(const char *, const char *);

// sort input lines
int main(int argc, char *argv[]) {
    int numLines;   // number of input lines read
    int numeric = 0;    // 1 if numeric sort

    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if ((numLines = readLines(lines, MAXLINES)) >= 0) {
        myQsort((void **) lines, 0, numLines - 1,
              (int (*)(const void *, const void *))(numeric ? numCmp : strcmp));
        writeLines(lines, numLines);

        return 0;
    } else {
        printf("input too big to sort\n");

        return 1;
    }
}

void myQsort(void *v[], int left, int right, int (*comp)(const void *, const void *)) {
    int i, last;

    if (left >= right) // do nothing if array contains fewer than 2 elements

        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }
    swap(v, left, last);
    myQsort(v, left, last-1, comp);
    myQsort(v, last+1, right, comp);
}

// swap two pointers
void swap(void *v[], int i, int j) {
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// numCmp: compare s1 and s2 numerically
int numCmp(const char *s1, const char *s2) {
    double v1, v2;

    v1 = strtod(s1, NULL);
    v2 = strtod(s2, NULL);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

// readLines: read input lines
int readLines(char *linePtr[], int maxLines) {
    int len, numLines;
    char *p, line[MAXLEN];

    numLines = 0;
    while ((len = getLine(line, MAXLEN)) > 0) {
        if (numLines >= maxLines || (p = alloc(len)) == NULL) {
            return -1;

        } else {
            line[len-1] = '\0'; // delete newline
            strcpy(p, line);
            linePtr[numLines++] = p;
        }
    }

    return numLines;
}

// getLine: read a line into s, return length
int getLine(char *s, int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {   // it fits
        allocp += n;

        return allocp - n;                      // old p
    } else {                                    // not enough room
        return 0;
    }
}


// writelines: write output lines
void writeLines(char *linePtr[], int numLines) {
    int i;
    for (i = 0; i < numLines; i++)
        printf("%s\n", linePtr[i]);
}