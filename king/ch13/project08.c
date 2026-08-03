/*
 * Project 8 from Chapter 13 of King: Modify Programming Project 5 from Chapter
 * 8 so that it includes the following function:
 *
 *      int compute_scrabble_value(const char *word);
 *
 * The function returns the SCRABBLE value of the string pointed to by word.
 */

#include <ctype.h>
#include <stdio.h>

#define MAXLEN 15

int compute_scrabble_value(const char *);

int main(void)
{
    char word[MAXLEN+1];
    printf("Enter a word: ");
    scanf("%15s", word);
    printf("Scrabble value: %d\n", compute_scrabble_value(word));

    return 0;
}

int compute_scrabble_value(const char *word)
{
    int sum = 0,
        values[]  = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
                     1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    while (*word)
        sum += values[toupper(*word++) - 'A'];

    return sum;
}
