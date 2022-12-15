#ifndef CALC_H
#define CALC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

enum Operator {
  NUMBER = '0',
  ADD    = '+',
  SUB    = '-',
  DIV    = '/',
  MUL    = '*',
  MOD    = '%',
  POW    = '^',
  SIN    = '~',
  EXP    = 'E'
};

enum CalcOperation {
  PRINT      = '?',
  SWAP       = 'S',
  DUPLICATE  = 'D',
  CLEAR      = 'C',
  VAR_ASSIGN = '=',
  VAR_ACCESS = '$'
};

#define MAXOP 100

//--------------------------------------------------- Calculator functions --//
/**
  * @brief Start the RPN calculator.
*/
void runcalc(void);

/**
  * @brief Prints help text and calculator's supported operations to stdout.
*/
void printhelp(void);

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
  * @brief Get the number from the top of the stack without popping it.
*/
double peek(void);

/**
  * @brief Swap the top two numbers in the stack. Returns whether the operation
  *   was successful.
*/
bool swaptop(void);

/**
  * @brief Duplicate the top number on the stack. Returns whether the operation
  *   was successful.
*/
bool dup(void);

/**
  * @brief Clear the stack.
*/
void clear(void);

#ifdef __cplusplus
}
#endif

#endif // CALC_H
