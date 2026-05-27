/*
 * Exercise 1-9 from K & R: Write a program to copy its input to its output,
 * replacing each string of one or more blanks by a single blank.
 */

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main(void)
{
   int c, prev_blank = FALSE;

   while ((c = getchar()) != EOF) {
      if (c == ' ') {
         if (!prev_blank) {
            putchar(c);
            prev_blank = TRUE; 
         }
      } else {
         putchar(c);
         prev_blank = FALSE;
      }
   }

   return 0;
}
