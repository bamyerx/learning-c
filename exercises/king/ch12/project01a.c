/*
 * Project 1(a) from Chapter 12 of King: Write a program that reads a message,
 * then prints the reversal of the message:
 *
 *      Enter a message: Don't get mad, get even.
 *      Reversal is: .neve teg,dam teg t'noD
 */

#include <stdio.h>

#define MAXMSG 100

int main(void)
{
    int i = 0;
    char msg[MAXMSG], c;

    printf("Enter a message: ");
    for (i = 0; i < MAXMSG && (c = getchar()) != '\n'; i++)
        msg[i] = c;
    printf("Reversal is: ");
    while (i > 0)
        putchar(msg[--i]);
    putchar('\n');

    return 0;
}
