#ifndef STRUTILS_H
#define STRUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Converts a string into a floating point value. Handles decimal
 *  points, an optional negative sign value, scientific notation,
 *  e.g. 123.45e-6, and the presence or absence of either the integer part or
 *  fractional part, e.g. 42 or .167
*/
double stof(const char s[]);

#ifdef __cplusplus
}
#endif

#endif // STRUTILS_H
