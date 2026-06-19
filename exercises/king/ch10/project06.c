/*
 * Project 6 from Chapter 10 of King: Write a program that evaluates Reverse
 * Polish Notation (RPN) expressions. The operands will be single-digit integers.
 * The operators are +, -, *, /, and =. The = operator causes the top stack item
 * to be displayed; afterwards, the stack is cleared and the user is prompted to
 * enter another expression. The process continues until the user enters a
 * character that is not an operator or operand:
 *
 *    Enter an RPN expression: 1 2 3 * + =
 *    Value of expression: 7
 *    Enter an RPN expression: 5 8 * 4 9 / =
 *    Value of expression: -8
 *    Enter an RPN expression: q
 *
 * If the stack overflows, the program will display the message Expression is
 * too complex and terminate. If the stack underflows (because of an expression
 * such as 1 2 + +), the program will display the message Not Enough operands in
 * expression and terminate.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void)
{
   char c;
   int temp;
   
   make_empty();
   for (;;) {
      printf("Enter an RPN expression: ");
      scanf(" %c", &c);
      do {
         if (c == '=') {
            printf("Value of expression: %d\n", pop());
            make_empty();
            break;
         } else if (c >= '0' && c <= '9') {
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
            } else {
               push(pop() / temp);
            }
         } else {
            exit(EXIT_SUCCESS);
         }
         scanf(" %c", &c);
      } while (c != '\n');
   }

   return 0;
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
