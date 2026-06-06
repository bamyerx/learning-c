/*
 * Project 13 from Chapter 7 of King: Write a program that calculates the
 * average word length for a sentence:
 * 
 *    Enter a sentence: It was deja vu all over again.
 *    Average word length: 3.4
 *
 * For simplicity, your program should consider a punctuation mark to be part
 * of the word to which it is attached. Display the average word length to one
 * decimal place.
 */

#include <stdio.h>

int main(void)
{
   int c, charcount, wordcount;

   printf("Enter a sentence: ");
   while ((c = getchar()) != '\n') {
      if (c != ' ') {
         charcount++;
      } else {
         wordcount++;
      }
   }
   wordcount++;
   printf("Average word length: %.1f\n", (float) charcount / wordcount);
   
   return 0;
}
