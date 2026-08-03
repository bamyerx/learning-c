/*
 * Project 14 from Chapter 13 of King: Modify Programming Project 16 from
 * Chapter 8 so that it includes the following function:
 *
 *      bool are_anagrams(const char *word1, const char *word2);
 *
 * The function returns true if the strings pointed to by word1 and word2 are
 * anagrams.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define MAXWORD 20

bool are_anagrams(const char *, const char*);

int main(void)
{
   char word1[MAXWORD], word2[MAXWORD];

   printf("Enter first word: ");
   scanf("%s", word1);
   printf("Enter second word: ");
   scanf("%s", word2);
   if (are_anagrams(word1, word2))
      printf("The words are anagrams.\n");
   else
      printf("The words are not anagrams.\n");

   return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
    char c;
    int i, letters_seen[26] = {0};

    while (*word1) {
        c = toupper(*word1++);
        if (c >= 'A' && c <= 'Z')
            letters_seen[c - 'A']++;
    }
    while (*word2) {
        c = toupper(*word2++);
        if (c >= 'A' && c <= 'Z')
            letters_seen[c - 'A']--;
    }
    for (i = 0; i < 26; i++)
        if (letters_seen[i] != 0)
            return false;
    return true;
}
