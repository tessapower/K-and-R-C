#ifndef GETCH_H
#define GETCH_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stdbool.h"

int getch(void);
int peekch(void);
bool ungetch(int);
void ungets(const char s[]);
void clearbuf(void);

#ifdef __cplusplus
}
#endif

#endif // GETCH_H