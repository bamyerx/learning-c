/*
 * Project 2(a) from Chapter 12 of King: Write a program that reads a message,
 * then checks whether it's a palindrome (the letters in the message are the
 * same from left to right as from right to left):
 *
 *      Enter a message: He lived as a devil, eh?
 *      Palindrome
 *
 *      Enter a message: Madam, I am Adam.
 *      Not a palindrome
 *
 * Ignore all characters that aren't letters. Use integer variables to keep
 * track of positions in the array.
 */

#include <stdio.h>
#include <ctype.h>

#define MAXMSG 100

int main(void)
{
    int i = 0, j = 0;
    char msg[MAXMSG], c;

    printf("Enter a message: ");
    while (i < MAXMSG && (c = getchar()) != '\n')
        if (isalpha(c))
            msg[i++] = toupper(c);
    while (j < i)
        if (msg[--i] != msg[j++]) {
            printf("Not a palindrome\n");
            return 0;
        }
    if (j >= i)
        printf("Palindrome\n");

    return 0;
}
