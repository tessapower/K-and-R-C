//
// Created by Tessa Power on 24/09/21.
//

#include <stdio.h>

void strCpy(char *s, const char *t);
void strCpy_with_pointers(char *s, char *t);

int main(int argc, char *argv[]) {
    // ????

    return 0;
}

// strcpy: copy t to s; array subscript version
void strCpy(char *s, const char *t) {
    int i = 0;
    while ((s[i] = t[i]) != '\0') {
        i++;
    }
}

// strcpy: copy t to s; pointer version
void strCpy_with_pointers(char *s, char *t) {
    while ((*s++ = *t++))
        ;
}
