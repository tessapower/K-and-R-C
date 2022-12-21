#ifndef EXPR_H
#define EXPR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

enum Operator {
  ADD = '+',
  SUB = '-',
  MUL = '*',
  DIV = '/'
};

enum Type {
  OPERATOR,
  NUMBER,
  UNKNOWN
};

/**
 * @brief Parses the given argument. Returns true if the argument was
 *  successfully parsed.
*/
bool parse(const char *arg);

/**
 * @brief Returns the Type of the given arg.
*/
enum Type type(const char* arg);

/**
 * @brief Whether this character is an operator.
*/
static bool isoperator(const char* arg);

/**
 * @brief Whether s is a negative number.
*/
static bool isnegnum(const char *s);

/**
 * @brief Puts the result of the calculation so far into res. Returns true if
 *  the expression was valid syntactically.
*/
bool result(double *res);

/**
 * @brief Push the given number onto the stack. Returns whether the number was
 *   successfully pushed.
*/
static bool push(const double operand);

/**
 * @brief Takes the number off of the top of the stack. Returns 0.0 if the
 *   stack is empty.
*/
static double pop(void);

/**
 * @brief Returns the number on the top of the stack without removing it.
 *   Returns 0.0 if the stack is empty.
*/
static double peek(void);

/**
 * @brief The size of the stack.
*/
static int size(void);

/**
 * @brief Whether the stack is empty or not.
*/
static bool isempty(void);

/**
 * @brief Clear the stack of operands. This should only be used for testing
 *   purposes.
*/
void clear(void);

#ifdef __cplusplus
}
#endif

#endif // EXPR_H