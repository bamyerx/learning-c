/*
 * Exercise 3-3 from K&R: Write a function expand(s1,s2) that expands shorthand
 * notations like a-z in the string s1 into the equivalent complete list 
 * abc...xyz in s2. Allow for letters of either case and digits, and be prepared
 * to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or
 * trailing - is taken literally.
 */

#include <ctype.h>

void expand(char s1[], char s2[])
{
    int c, i, j;

    for (i = j = 0; s1[i] != '\0'; i++, j++)
        if (s1[i] == '-' &&
            i > 0 && s1[i + 1] != '\0' &&
            s1[i - 1] <= s1[i + 1] &&
            (
                (isupper(s1[i - 1]) && isupper(s1[i + 1])) ||
                (islower(s1[i - 1]) && islower(s1[i + 1])) ||
                (isdigit(s1[i - 1]) && isdigit(s1[i + 1]))
            ))
            for (c = s1[i - 1] + 1; c < s1[i + 1]; c++)
                s2[j++] = c;
        else
            s2[j] = s1[i];
    s2[j] = '\0';
}
