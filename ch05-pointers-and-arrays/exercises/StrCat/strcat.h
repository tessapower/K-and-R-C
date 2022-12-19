#ifndef STRCAT_H
#define STRCAT_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Concatenate t onto the end of s; s must be big enough
*/
void strconcat(char *s, char *t);

#ifdef __cplusplus
}
#endif

#endif // STRCAT_H
