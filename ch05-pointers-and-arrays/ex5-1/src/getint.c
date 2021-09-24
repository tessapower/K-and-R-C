//
// Created by Tessa Power on 24/09/21.
//

// As written, `getint` treats a '+' or '-' not followed by a digit as a valid
// representation of zero. Fix it to push such a character back on the input.

#include <ctype.h>
#include <stdio.h>

#include "../include/getint.h"

#define BUFSIZE 100

char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;       // next free position in buf

int getch(void);

void ungetch(int);

int getint(int *pn) {
    int c;

    while (isspace(c = getch()))    // skip whitespace
        ; // no-op

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); // it's not a number

        return 0;
    }

    int sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        int next = getch();
        if (!isdigit(next)) {
            ungetch(next);
            ungetch(c);

            return 0;
        }
        c = next;
    }

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

// get a (possibly pushed back) character
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// push character back on input
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters!\n");
    else
        buf[bufp++] = c;
}
