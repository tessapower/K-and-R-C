#ifndef CALC_H
#define CALC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#define NUMBER '0'
#define ADD '+'
#define SUB '-'
#define DIV '/'
#define MUL '*'
#define MOD '%'
#define MAXOP 100

//--------------------------------------------------- Calculator functions --//
/**
  * @brief Start the RPN calculator.
*/
void runcalc(void);

/**
  * @brief Get the next operator or numeric operand. Floating-point numbers and
  *   negative numbers are supported.
*/
int getop(char[]);

//------------------------------------------------------- Stack operations --//
/**
 * @brief Push a number onto the stack. Returns whether the operation was
 *   successful.
 */
bool push(double);

/**
 * @brief Get the number on top the stack. Returns 0.0 when the stack is empty.
 */
double pop(void);

/**
 * @brief Clear the stack.
*/
void clear(void);

//-------------------------------------------------------- Input functions --//
/**
 * @brief Read the next char from stdin without removing it from the buffer.
*/
int peekch(void);

/**
 * @brief Read the next char from stdin.
*/
int getch(void);

/**
 * @brief Unread the given char, pushing it back onto the input buffer.
*/
void ungetch(int);

/**
  * @brief Clear the input buffer. This function is only for testing purposes
  *   and should not really be used.
*/
void clearbuf(void);

#ifdef __cplusplus
}
#endif

#endif // CALC_H
