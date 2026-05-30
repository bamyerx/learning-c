/*
 * Exercise 1-21 from K&R: Write a program entab that replaces strings of
 * blanks by the minimum number of tabs and blanks to achieve the same spacing.
 * Use the same tab stops as for detab.
 */

#include <stdio.h>

#define TABSTOP 8

int main(void)
{
   int i, c, n;

   i = 0;
   n = 0;
   while ((c = getchar()) != EOF) {
      /* end of line; reset column counter and print pending blanks */
      if (c == '\n') {
         while (n > 0) {
            putchar(' ');
            --n;
         }
         putchar('\n');
         i = 0;
      } else if (c == ' ') {
         if ((i + n + 1) % TABSTOP == 0) {
            /* prefer a blank to a tab if only a blank is sufficient */
            if (n == 0) {
               putchar(' ');
            } else {
               putchar('\t');
            }
            i += n + 1;
            n = 0;
         } else {
            ++n;
         }
      } else {
         /* when a non-blank character is seen, print pending blanks */
         while (n > 0) {
            putchar(' ');
            --n;
            ++i;
         }
         putchar(c);
         ++i;
      }
   }
   /* print any pending blanks at the end of the file */
   if (n != 0) {
      while (n > 0) {
         putchar(' ');
         --n;
      }
   }

   return 0;
}
