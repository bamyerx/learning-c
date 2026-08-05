/*
 * Project 1(b) from Chapter 12 of King: Write a program that reads a message,
 * then prints the reversal of the message:
 *
 *      Enter a message: Don't get mad, get even.
 *      Reversal is: .neve teg,dam teg t'noD
 *
 * Revise the program to use a pointer instead of an integer to keep track of
 * the current position in the array.
 *
 * Note: This is also my solution to Project 3.
 */

#include <stdio.h>

#define MAXMSG 100

int main(void)
{
    char msg[MAXMSG], *p;

    printf("Enter a message: ");
    for (p = msg; p < msg + MAXMSG && (*p = getchar()) != '\n'; p++)
        ;
    printf("Reversal is: ");
    while (p > msg)
        putchar(*--p);
    putchar('\n');

    return 0;
}
