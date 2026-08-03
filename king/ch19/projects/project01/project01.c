/*
 * Project 1 from Chapter 19 of King: Modify Programming Project 1 from Chapter
 * 10 so that it uses the stack ADT described in Section 19.4. You may use any
 * of the implementations of the ADT described in that section.
 */

#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

int main(void)
{
   char c;
   Stack s;

   printf("Enter parentheses and/or braces: ");
   s = create();
   make_empty(s);
   while ((c = getchar()) != '\n') {
      if (c == '(' || c == '{')
         push(s, c);
      else if ((c == ')' && pop(s) != '(') || (c == '}' && pop(s) != '{')) {
         printf("Parentheses are not nested properly\n");
         return 0;
      }
   }
   if (is_empty(s))
      printf("Parentheses/braces are nested properly\n");
   else
      printf("Parentheses/braces are not nested properly\n");
   
   return 0;
}
