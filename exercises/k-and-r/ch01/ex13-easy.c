/*
 * Exercise 1-13 from K & R: Write a program to print a historgram of the
 * lengths of words in its input.
 *
 * Version 1: Horizontal histogram (easy)
 */

#include <stdio.h>

#define MAX_WORD_LENGTH 100

int main(void)
{
   int c, len = 0;
   int word_lengths[MAX_WORD_LENGTH];

   for (int i = 0; i < MAX_WORD_LENGTH; i++) {
      word_lengths[i] = 0;
   }

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

   int max = 0;
   for (int i = MAX_WORD_LENGTH - 1; i >= 0; i--) {
      if (word_lengths[i] != 0) {
         max = i;
         break;
      }
   }

   for (int i = 1; i <= max; i++) {
      printf("%3d | ", i);
      for (int j = 0; j < word_lengths[i]; j++) {
         printf("=");
      }
      printf("\n");
   }

   return 0;
}
