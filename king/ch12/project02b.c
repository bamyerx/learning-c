/*
 * Project 2(b) from Chapter 12 of King: Write a program that reads a message,
 * then checks whether it's a palindrome (the letters in the message are the
 * same from left to right as from right to left):
 *
 *      Enter a message: He lived as a devil, eh?
 *      Palindrome
 *
 *      Enter a message: Madam, I am Adam.
 *      Not a palindrome
 *
 * Ignore all characters that aren't letters. Revise the program to use pointers
 * instead of integers to keep track of positions in the array.
 *
 * Note: This is also my solution to Project 4.
 */

#include <stdio.h>
#include <ctype.h>

#define MAXMSG 100

int main(void)
{
    char msg[MAXMSG], c, *p, *q;

    printf("Enter a message: ");
    p = q = msg;
    while (p < msg + MAXMSG && (c = getchar()) != '\n')
        if (isalpha(c))
            *p++ = toupper(c);
    while (q < p)
        if (*--p != *q++) {
            printf("Not a palindrome\n");
            return 0;
        }
    if (q >= p)
        printf("Palindrome\n");

    return 0;
}
