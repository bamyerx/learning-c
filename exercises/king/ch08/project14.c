/*
 * Project 14 of Chapter 8 from King: Write a program that reverses the words in
 * a sentence:
 * 
 *    Enter a sentence: you can cage a swallow can't you?
 *    Reversal of sentence: you can't swallow a cage can you?
 */

#include <stdio.h>

#define MAX_LENGTH 1000

int main(void)
{
   char sentence[MAX_LENGTH] = {0};
   char c, terminator;
   int i, j;

   printf("Enter a sentence: ");
   i = 0;
   while ((c = getchar()) != '.' && c != '?' && c != '!' && c != '\n') {
      sentence[i] = c;
      i++;
   }
   sentence[i] = c;
   terminator = c;
   
   printf("Reversal of sentence: ");
   while (i >= 0) {
      while (sentence[i] != ' ' && i >= 0)
         i--;
      for (j = i + 1; sentence[j] != ' ' && sentence[j] != terminator; j++)
         printf("%c", sentence[j]);
      if (i >= 0)
         printf(" ");
      else 
         printf("%c", terminator);
      i--;
   }
   if (terminator != '\n')
      printf("\n");

   return 0;
}
