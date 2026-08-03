/*
 * Exercise 4-11 from K&R: Modify getop so that it doesn't need to use getch.
 * Hint: use an internal static variable.
 */

#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i;
    static int c;

    while (c == '\0' || c == ' ' || c == '\t')
        c = getchar();
    s[0] = c;
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
        c = getchar();
        return s[0];
    }
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getchar()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getchar()))
            ;
    s[i] = '\0';
    return NUMBER;
}
