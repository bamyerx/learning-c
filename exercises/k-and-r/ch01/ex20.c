/*
 * Exercise 1-20 from chapter 1 of K&R: Write a program detab that replaces
 * tabs in the input with the proper number of blanks to space to the next tab
 * stop. Assume a fixed set of tab stops, say every n columns.
 */

#include <stdio.h>

#define TABSTOP 8

int main(void)
{
   int i, n, c;

   i = 0;
   while ((c = getchar()) != EOF) {
      if (c == '\n') {
         i = 0;
         putchar('\n');
      } else if (c == '\t') {
         n = i % TABSTOP;
         for (int j = n; j < TABSTOP; ++j, ++i) {
            putchar(' ');
         }
      } else {
         putchar(c);
         ++i;
      }
   }

   return 0;
}
