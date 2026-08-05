/*
 * Project 9 from Chapter 13 of King: Modify Programming Project 10 from Chapter
 * 7 so that it includes the following function:
 *
 *      int compute_vowel_count(const char *sentence);
 *
 * The function returns the number of vowels in the string pointed to by the
 * sentence parameter.
 */

#include <ctype.h>
#include <stdio.h>

#define MAXLEN 1000

int compute_vowel_count(const char *);
int readline(char [], int);

int main(void)
{
    char sentence[MAXLEN];

    printf("Enter a sentence: ");
    readline(sentence, MAXLEN);
    printf("Your sentence contains %d vowels.\n", compute_vowel_count(sentence));

   return 0;
}

int compute_vowel_count(const char *sentence)
{
    int vowels = 0;
    char c;

    while ((c = toupper(*sentence++))) 
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            vowels++;
    return vowels;
}

int readline(char sentence[], int len)
{
    int c, i;

    for (i = 0; (c = getchar()) != '\n'; i++)
        if (i < len)
            sentence[i] = c;
    sentence[i] = '\0';
    return i;
}
