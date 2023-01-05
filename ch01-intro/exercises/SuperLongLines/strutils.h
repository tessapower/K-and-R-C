#pragma once
/**
 * @brief Put a line with maximum length of lim into s using the given function
 *  for fething chararacters.
*/
int getline(char s[], const int lim, int (*getc)());

/**
 * @brief Copy the string source into dest, dest must be large enough.
*/
void copy(char dest[], char source[]);
