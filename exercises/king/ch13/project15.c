/*
 * Project 15 from Chapter 13 of King: Modify Programming Project 6 of Chapter
 * 10 so that it includes the following function:
 *
 *      int evaluate_RPN_expression(const char *expression);
 *
 * The function returns the value of the RPN expression pointed to by
 * expression.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100
#define MAXLEN 1000

int contents[STACK_SIZE];
int top = 0;

int evaluate_RPN_expression(const char *expression);
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void)
{
   char c, expression[MAXLEN];
   int i;
   
   make_empty();
   for (;;) {
      printf("Enter an RPN expression: ");
      i = 0;
      while ((c = getchar()) != '=')
        if (i < MAXLEN && c != ' ')
            expression[i++] = c;
      expression[i] = '\0';
      printf("Value of expression: %d\n", evaluate_RPN_expression(expression));
      make_empty();
      while (getchar() != '\n')
          ;
   }

   return 0;
}

int evaluate_RPN_expression(const char *expression)
{
    char c, temp;

    while ((c = *expression++)) {
        if (c >= '0' && c <= '9') {
            push(c - '0');
        } else if (c == '+') {
            push(pop() + pop());
        } else if (c == '-') {
            temp = pop();
            push(pop() - temp);
        } else if (c == '*') {
            push(pop() * pop());
        } else if (c == '/') {
            temp = pop();
            if (temp == 0) {
                printf("Invalid expression; cannot divide by zero\n");
                exit(EXIT_FAILURE);
            } else
                push(pop() / temp);
        } else {
            exit(EXIT_SUCCESS);
        }
    }
    return pop();
}

void make_empty(void)
{
   top = 0;
}

bool is_empty(void)
{
   return top == 0;
}

bool is_full(void)
{
   return top == STACK_SIZE;
}

void push(int i)
{
   if (is_full())
      stack_overflow();
   else
      contents[top++] = i;
}

int pop(void)
{
   if (is_empty())
      stack_underflow();
   else
      return contents[--top];
}

void stack_overflow(void)
{
   printf("Expression is too complex\n");
   exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
   printf("Not enough operands in expression\n");
   exit(EXIT_FAILURE);
}
