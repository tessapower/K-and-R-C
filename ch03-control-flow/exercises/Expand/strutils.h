#ifndef STRUTILS_H
#define STRUTILS_H

#include <stdbool.h>

/**
 * @brief Copies the characters from s1 to s2, expanding any shorthand notation
 *   such as a-z, A-Z, 0-9 into the equivalent complete list. E.g. a-z expands
 *   to abc...xyz, A-Z expands to ABC...XYZ, and 0-9 expands to 0...9.
*/
void expand(char s1[], char s2[]);

/**
 * @brief Returns whether the range is valid. A valid range is one that starts
 *   and ends with an uppercase letter, a lowercase letter, or a digit. 
 *   Examples of valid ranges include: A-F, 2-6, l-m-p, a-z0-9. Ranges cannot
 *   be mixed, so for example A-z, 0-9-A, and a-Z are invalid ranges.
*/
bool isvalidrange(const int start, const int end);

#endif  // STRUTILS_H
