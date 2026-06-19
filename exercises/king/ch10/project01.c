/*
 * Project 1 from Chapter 10 of King: Modify the stack example of Section 10.2
 * so that it stores characters instead of integers. Next add a main function
 * that asks the user to enter a series of parentheses and/or braces, then
 * indicates whether or not they're proplery nested:
 *
 *    Enter parentheses and/or braces: ((){}{()})
 *    Parentheses/braces are nested properly
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
void push(char c);
char pop(void);
void stack_overflow();
void stack_underflow();

int main(void)
{
   char c;

   printf("Enter parentheses and/or braces: ");
   make_empty();
   while ((c = getchar()) != '\n') {
      if (c == '(' || c == '{')
         push(c);
      else if ((c == ')' && pop() != '(') || (c == '}' && pop() != '{')) {
         printf("Parentheses are not nested properly\n");
         exit(EXIT_SUCCESS);
      }
   }
   if (is_empty())
      printf("Parentheses/braces are nested properly\n");
   else
      printf("Parentheses/braces are not nested properly\n");
   
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

void push(char c)
{
   if (is_full())
      stack_overflow();
   else
      contents[top++] = c;
}

char pop(void)
{
   if (is_empty()) {
      stack_underflow();
      exit(EXIT_SUCCESS);
   } else
      return contents[--top];
}

void stack_overflow()
{
   printf("Stack overflow\n");
   exit(EXIT_FAILURE);
}

void stack_underflow()
{
   printf("Parentheses are not nested properly\n");
}
