/*
 * Exercise 1-14 from K & R: Write a program to print a histogram of the
 * frequencies of different characters in its input.
 *
 * Note: The characters counted are limited to the ASCII printable characters
 * excluding space (32) and delete (127).
 */

#include <stdio.h>

#define CHARSET_MIN 33  // the first valid ASCII code '!'
#define CHARSET_MAX 126 // the last valid ASCII code '~'

int main(void)
{
   int c;
   int nchars[CHARSET_MAX + 1];

   /* Initialize character count array. */
   for (int i = 0; i <= CHARSET_MAX; i++) {
      nchars[i] = 0;
   }

   /* Count characters. */
   while ((c = getchar()) != EOF) {
      if (c >= CHARSET_MIN && c <= CHARSET_MAX) {
         nchars[c]++;
      }
   }

   /* Print the histogram. */
   for (int i = CHARSET_MIN; i <= CHARSET_MAX; i++) {
      putchar(i);
      printf(" | ");
      for (int j = 1; j <= nchars[i]; j++) {
         printf("=");
      }
      printf("\n");
   }

   return 0;
}
