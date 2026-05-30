/*
 * Exercise 1-22 from chapter 1 of K&R: Write a program to "fold" long input
 * lines into two or more shorter lines after the last non-blank character that
 * occurs before the n-th cloumn of input.
 */

#include <stdio.h>

#define TABSTOP 8
#define LINEWIDTH 80

int main(void)
{
   int i = 0; /* column counter for input line */
   int j = 0; /* buffer character counter */
   int n = 0; /* pending blanks counter */
   int c;     /* current character */

   /* buffer needs capacity for a full line +  null terminator */
   char buffer[LINEWIDTH + 1];

   while ((c = getchar()) != EOF) {
      if (c == ' ' || c == '\t' || c ==  '\n') {
         if (j > 0) { 
            buffer[j] = '\0';
            /* if the pending blanks and buffered word exceed LINEWIDTH,    */
            /* discard the blanks and print the buffered word on a new line */
            if (i + n + j > LINEWIDTH) {
               putchar('\n');
               n = 0;
               i = 0;
            }
            /* print pending blanks */
            while (n > 0) {
               putchar(' ');
               --n;
               ++i;
            }
            /* print buffered word */
            printf("%s", buffer);
            i += j;
            j = 0;
         }
         /* discard pending blanks and reset column counter for new line */
         if (c == '\n') {
            putchar('\n');
            i = 0;
            n = 0;
         /* convert tabs to the correct number of pending blanks */
         } else if (c == '\t') {
            n += TABSTOP - (i + n) % TABSTOP;
         } else {
            ++n;
         }
         /* non white-space characters are added to the buffer */
      } else {
         buffer[j] = c;
         ++j;
         /* if the buffer is full, print it on its own line */
         if (j == LINEWIDTH) {
            if (i != 0) {
               putchar('\n');
            }
            buffer[j] = '\0';
            printf("%s", buffer);
            j = 0;
            n = 0;
            i = LINEWIDTH;
         }
      }
   }
   /* print the buffered word and preceding blanks when EOF is reached */ 
   if (j > 0) {
      buffer[j] = '\0';
      if (i + n + j > LINEWIDTH) {
         putchar('\n');
         n = 0;
         i = 0;
      }
      while (n > 0) {
         putchar(' ');
         --n;
         ++i;
      }
      printf("%s", buffer);
      i += j;
      j = 0;
   }
}

