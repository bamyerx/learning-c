/*
 * Exercise 1-13 from K & R: Write a program to print a histrogram of the
 * lengths of words in its input.
 *
 * Version 2: Vertical histogram (hard)
 */

#include <stdio.h>

#define MAX_WORD_LENGTH 100

int main(void)
{
   int c, len = 0;
   int word_lengths[MAX_WORD_LENGTH];

   /* Initialize the word length array. */
   for (int i = 0; i < MAX_WORD_LENGTH; i++) {
      word_lengths[i] = 0;
   }

   /* Populate the array with word lengths from input. */
   while ((c = getchar()) != EOF) {
      if (c == ' ' || c == '\t' || c == '\n') {
         if (len != 0 && len < MAX_WORD_LENGTH){
            word_lengths[len]++;
         }
         len = 0;
      } else {
         len++;
      }
   }
   if (len != 0 && len < MAX_WORD_LENGTH) {
      word_lengths[len]++;
   }

   /* Find the maximum word length in the array. */
   int max_len = 0;
   for (int i = MAX_WORD_LENGTH - 1; i >= 0; i--) {
      if (word_lengths[i] != 0) {
         max_len = i;
         break;
      }
   }

   /* Find the maximum bar height for the histogram. */
   int max_height = 0;
   for (int i = 1; i <= max_len; i++) {
      if (word_lengths[i] > max_height) {
         max_height = word_lengths[i];
      }
   }

   /* Print the histogram. */
   for (int i = max_height; i >= -1; i--) {
      for (int j = 1; j <= max_len; j++) {
         if (i > 0) {
            if (word_lengths[j] >= i) {
               printf(" []");
           } else {
               printf("   ");
           }
         }
         if (i == 0) {
            printf("---");
         }
         if (i == -1) {
            printf("%3d", j);
         }
      }
      printf("\n");
   }

   return 0;
}
