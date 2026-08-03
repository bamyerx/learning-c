/*
 * Project 4 from Chapter 9 of King: Modify Programming Project 16 of Chapter 8
 * so that it includes the following functions:
 *
 *    void read_word(int counts[26]);
 *    bool equal_array(int counts1[26], int counts2[26]);
 *
 * main will call read_word twice, once for each of the two words entered by
 * the user. As it reads a word, read_word will use the letters in the word to
 * update the counts array, as described in the original project. main will then
 * call equal_array, passing it the two arrays. equal_array will return true if
 * the elements in the two arrays are identical (indicating that the words are
 * anagrams) and false otherwise.
 */

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

void read_word(int counts[26]);
bool equal_array(int counts1[26], int counts2[26]);

int main(void)
{
   int counts1[26] = {0};
   int counts2[26] = {0};

   printf("Enter first word: ");
   read_word(counts1);
   printf("Enter second word: ");
   read_word(counts2);
   if (equal_array(counts1, counts2))
      printf("The words are anagrams.\n");
   else
      printf("The words are not anagrams.\n");

   return 0;
}

void read_word(int counts[26])
{
   char c;
   while ((c = getchar()) != '\n') {
      if (toupper(c) >= 'A' && toupper(c) <= 'Z')
         counts[toupper(c) - 'A']++;
   }
}

bool equal_array(int counts1[26], int counts2[26])
{
   for (int i = 0; i < 26; i++)
      if (counts1[i] != counts2[i])
         return false;
   return true;
}
