/*
 * Project 10 from Chapter 7 of King: Write a program that counts the number of
 * vowels (a, e, i, o, and u) in a sentence:
 *
 *    Enter a sentence: And that's the way it is.
 *    Your sentence contains 6 vowels.
 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
   int c, n;

   n = 0;
   printf("Enter a sentence: ");
   while ((c = getchar()) != '.') {
      c = toupper(c);
      if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
         n++;
      }
   }
   printf("Your sentence contains %d vowels.\n", n);

   return 0;
}
