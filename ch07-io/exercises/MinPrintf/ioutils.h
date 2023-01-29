#ifndef IOUTILS_H
#define IOUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>

/**
 * @brief minimal printf with variable argument list
*/
void minprintf(const char* fmt, ...);

#ifdef __cplusplus
}
#endif

#endif // IOUTILS_H
