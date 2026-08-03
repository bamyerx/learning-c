/*
 * Project 5 of Chapter 12 from King: Modify Programming Project 14 of Chapter 8
 * so that it uses a pointer instead of an integer to keep track of the current
 * position in the array that contains the sentence.
 *
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
   char c, terminator, *p, *q;

   printf("Enter a sentence: ");
   p = sentence;
   while ((c = getchar()) != '.' && c != '?' && c != '!' && c != '\n') {
      *p = c;
      p++;
   }
   *p = c;
   terminator = c;
   
   printf("Reversal of sentence: ");
   while (p >= sentence) {
      while (*p != ' ' && p >= sentence)
         p--;
      for (q = p + 1; *q != ' ' && *q != terminator; q++)
         printf("%c", *q);
      if (p >= sentence)
         printf(" ");
      else 
         printf("%c", terminator);
      p--;
   }
   if (terminator != '\n')
      printf("\n");

   return 0;
}
