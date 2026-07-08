/*
 * Project 12 from Chapter 13 of King:  Modify Programming Project 14 from
 * Chapter 8 so that it stores the words in a two-dimensional char array as it
 * reads the sentence, with each row of the array storing a single word. Assume
 * that the sentence contains no more than 30 words and no word is more than 20
 * characters long. Be sure to store a null character at the end of each word so
 * that it can be treated as a string.
 */

#include <stdio.h>

#define MAXWORDS 30
#define MAXLEN 20

int main(void)
{
    char c, sentence[MAXWORDS][MAXLEN+1];
    int i, j;

    printf("Enter a sentence: ");
    i = j = 0;
    while ((c = getchar()) != '.' && c != '?' && c != '!' && c != '\n') {
        if (c != ' ') 
            sentence[i][j++] = c;
        else {
            sentence[i][j] = '\0';
            j = 0;
            sentence[++i][j] = c;
        }
    }
    sentence[i][j] = '\0';
   
    printf("Reversal of sentence:");
    while (i >= 0)
        printf(" %s", sentence[i--]);
    printf("%c", c);
    if (c != '\n')
        printf("\n");

    return 0;
}
