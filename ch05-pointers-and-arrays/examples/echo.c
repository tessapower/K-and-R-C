//
// Created by Tessa Power on 22/09/21.
//

#include <stdio.h>
/* echo command-line arguments; 1st version */
//int main(int argc, char *argv[]) {
//    int i;
//
//    for (i = 1; i < argc; i++)
//        printf("%s%s", argv[i], (i <argc-1) ? " " : "");
//    printf("\n");
//
//    return 0;
//}

/* echo command-line arguments; 2nd version */
// Since argv is a pointer to the beginning of the array of argument strings,
// incrementing it by 1 (++argv) makes it point at the original argv[1] instead
// of argv[0].
//
// Each successive increment moves it along to the next argument; *argv is then
// pointer to that argument.
int main(int argc, char *argv[]) {
    while (--argc > 0)
        printf((argc > 1) ? "%s " : "%s", *++argv);
    printf("\n");

    return 0;
}
