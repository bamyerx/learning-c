/*
 * Exercise 8 from chapter 1 of K & R.
 *
 * Counts blanks, tabs, and newlines from input.
 *
 */

#include <stdio.h>

int main(void)
{
   int c, nb, nt, nl;
   nb = nt = nl = 0;

   while ((c = getchar()) != EOF) {
      if (c == ' ')
         nb++;
      if (c == '\t')
         nt++;
      if (c == '\n')
         nl++;
   }
   printf("blanks: %d\ntabs: %d\nnewlines: %d\n", nb, nt, nl);

   return 0;
}
