/*
 * Project 16 from Chapter 8 of King: Write a program that tests whether two
 * words are anagrams (permutations of the same letters):
 *
 *    Enter first word: smartest
 *    Enter second word: mattress
 *    The words are anagams.
 *
 *    Enter first word: dumbest
 *    Enter second word: stumble
 *    The words are not anagrams.
 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
   int letters_seen[26] = {0};
   int c, i;

   printf("Enter first word: ");
   while ((c = getchar()) != '\n') {
      if (toupper(c) >= 'A' && toupper(c) <= 'Z')
         letters_seen[toupper(c) - 'A']++;
   }
   printf("Enter second word: ");
   while ((c = getchar()) != '\n') {
      if (toupper(c) >= 'A' && toupper(c) <= 'Z')
         letters_seen[toupper(c) - 'A']--;
   }
   for (i = 0; i < 26; i++)
      if (letters_seen != 0)
          printf("The words are not anagrams.\n");
   printf("The words are anagrams.\n");

   return 0;
}
