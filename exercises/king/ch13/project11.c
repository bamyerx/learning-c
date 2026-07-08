/*
 * Project 11 from Chapter 13 of King: Modify Programming Project 13 from
 * Chapter 7 so that it includes the following function:
 *
 *      double compute_average_word_length(const char *sentence);
 *
 * The function returns the average length of the words in the string pointed
 * to by sentence
 * 
 *    Enter a sentence: It was deja vu all over again.
 *    Average word length: 3.4
 *
 * For simplicity, your program should consider a punctuation mark to be part
 * of the word to which it is attached. Display the average word length to one
 * decimal place.
 */

#include <stdio.h>

#define MAXLEN 1000

double compute_average_word_length(const char *);
int readline(char [], int);

int main(void)
{
   char sentence[MAXLEN];

   printf("Enter a sentence: ");
   readline(sentence, MAXLEN);
   printf("Average word length: %.1f\n", compute_average_word_length(sentence));
   
   return 0;
}

double compute_average_word_length(const char *sentence)
{
    int i, charcount, wordcount;
    i = charcount = wordcount = 0;

    while (sentence[i++] != '\0')
        if (sentence[i] != ' ')
            charcount++;
        else
            wordcount++;
    wordcount++;

    return (double) charcount / wordcount;
}

int readline(char sentence[], int len)
{
    int c, i = 0;

    while ((c = getchar()) != '\n')
        if (i < len)
            sentence[i++] = c;
    sentence[i] = '\0';
    return i;
}
