//
// Created by Tessa Power on 24/09/21.
//

#include <stdio.h>
#include "getint.h"

#define SIZE 10

int main(int argc, char *argv[]) {
    int n, array[SIZE];

    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        printf("%d ", array[n]);

    return 0;
}
