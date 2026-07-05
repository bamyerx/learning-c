/* an implementation of a stack */

#include <stdbool.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int *top_ptr = contents;

void make_empty(void)
{
    top_ptr = contents;
}

bool is_empty(void)
{
    return top_ptr == contents;
}

bool is_full(void)
{
    return top_ptr == contents + STACK_SIZE;
}

void push(int i)
{
    if (is_full())
        stack_overflow();
    else
        *top_ptr++ = i;
}

int pop()
{
    if (is_empty())
        stack_underflow();
    else
        return *--top_ptr;
}
