//
// Created by Tessa Power on 22/09/21.
//

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getLine(char s[], int lim);

// find_with_params: print lines that match pattern from 1st arg
int main(int argc, char *argv[]) {
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

    while (--argc > 0 && (*++argv)[0] == '-')
        while ((c = *++argv[0]))
            switch(c) {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("find_with_params: illegal option %c\n", c);
                argc = 0;
                found = -1;
                break;
        }

    if (argc != 1)
        printf("Usage: find pattern\n");
    else
        while (getLine(line, MAXLINE) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                    printf("%ld: ", lineno);
                printf("%s", line);
                found++;
            }
        }

    return found;
}

// getLine: get line into s, return length
int getLine(char s[], int lim) {
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';

    return i;
}