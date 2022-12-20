#ifndef STRUTILS_H
#define STRUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

// Exercise 3-2: Write a function escape(s, t) that converts characters like
//  newline and tab into visible escape sequences like \n and \t as it copies
//  the string t to s. Use a switch. Write a function for the other direction
//  as well, converting escape sequences into the real characters.

void escape(char *s, char *t);
void unescape(char *s, char *t);

// Exercise 4-2: Extend atof to handle scientific notation in the form
//  123.45e-6 where a floating point number may be followed by e or E and an
//  optionally signed exponent.

double stof(const char *s);

#ifdef __cplusplus
}
#endif

#endif // STRUTILS_H
