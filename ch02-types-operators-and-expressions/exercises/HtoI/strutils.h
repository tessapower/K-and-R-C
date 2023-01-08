#ifndef STRUTILS_H
#define STRUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief converts a string of hex digits (including an optional 0x or 0X) into
 *  its equivalent integer value. Hex digits are 0-9, a-f, and A-F.
*/
int htoi(const char s[]);

#ifdef __cplusplus
}
#endif

#endif // STRUTILS_H