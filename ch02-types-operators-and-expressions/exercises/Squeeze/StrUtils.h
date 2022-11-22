#pragma once
#include <stdbool.h>

/**
 * Deletes any character from toDelete found in s.
*/
void squeeze(char s[], const char toDelete[]);

/**
 * Returns the index of the first occurrence of c, or -1 if not found.
*/
bool contains(const char s[], const int c);
