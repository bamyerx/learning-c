/*
 * Exercise 4-1 from K&R: Write the function strindex(s,t) which returns the
 * position of the rightmost occurrence of t in s, or -1 if there is none.
 */

#include <string.h>

int strindex(char s[], char t[])
{
    int i, j, k;

    for (i = strlen(s) - 1; i >= 0; i--) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}
