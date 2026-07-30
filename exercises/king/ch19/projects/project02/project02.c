/*
 * Project 2 from Chapter 19 of King: Modify Programming Project 6 from Chapter
 * 10 so that it uses the stack ADT described in Section 19.4. You may use any
 * of the implementations of the ADT described in that section.
 */

#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

int main(void)
{
   char c;
   int temp;
   Stack s;
   
   s = create();
   for (;;) {
      printf("Enter an RPN expression: ");
      scanf(" %c", &c);
      do {
         if (c == '=') {
            printf("Value of expression: %d\n", pop(s));
            make_empty(s);
            break;
         } else if (c >= '0' && c <= '9') {
            push(s, c - '0');
         } else if (c == '+') {
            push(s, pop(s) + pop(s));
         } else if (c == '-') {
            temp = pop(s);
            push(s, pop(s) - temp);
         } else if (c == '*') {
            push(s, pop(s) * pop(s));
         } else if (c == '/') {
            temp = pop(s);
            if (temp == 0) {
               printf("Invalid expression; cannot divide by zero\n");
               exit(EXIT_FAILURE);
            } else {
               push(s, pop(s) / temp);
            }
         } else {
            exit(EXIT_SUCCESS);
         }
         scanf(" %c", &c);
      } while (c != '\n');
   }

   return 0;
}
