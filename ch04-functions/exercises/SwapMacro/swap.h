#ifndef SWAP_H
#define SWAP_H

#ifdef __cplusplus
extern "C" {
#endif

// Exercise 4-14: Define a macro swap(t, x, y) that interchanges two arguments
//  of type t.

#define SWAP(t, x, y) { t _z; _z = x, x = y, y = _z; }

#ifdef __cplusplus
}
#endif

#endif // SWAP_H
