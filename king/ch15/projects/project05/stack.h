#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

/*
 * make_empty: Empty the stack.
 */
void make_empty(void);

/*
 * is_empty: Return 1 if stack is empty, 0 otherwise.
 */
bool is_empty(void);

/*
 * is_full: Return 1 if stack is full, 0 otherwise.
 */
bool is_full(void);

/*
 * push: Push an int onto the stack.
 */
void push(int i);

/*
 * pop: Pop and return the top value from the stack.
 */
int pop(void);

/*
 * stack_overflow: Print an error message and exit.
 */
void stack_overflow(void);

/*
 * stack_underflow: Print an error message and exit.
 */
void stack_underflow(void);

#endif
