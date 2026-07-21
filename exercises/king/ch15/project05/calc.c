/*
 * Project 5 from Chapter 15 of King: Modify Programming Project 6 from Chapter
 * 10 so that it has separate stack.h and stack.c files, as described in Section
 * 15.2.
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

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
