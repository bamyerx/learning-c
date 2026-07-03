/*
 * Exercise 4-12 from K&R: Adapt the ideas of printd to write a recursive
 * version of itoa; that is, convert an integer into a string by calling a
 * recursive routine.
 */

#include <stdio.h>

void itoa(int n, char s[])
{
    itoa_r(n, s, 0);
}

int itoa_r(int n, char s[], int i)
{
    if (n < 0) {
        s[i++] = '-';
        n = -n;
    }
    if (n / 10)
        i = itoa_r(n / 10, s, i);
    s[i++] = n % 10 + '0';
    s[i] = '\0';

    return i;
}
