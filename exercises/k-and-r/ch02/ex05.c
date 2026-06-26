/*
 * Exercise 2-5 from K&R: Write the function any(s1,s2) which returns the first
 * location in a string s1 where any character from the string s2 occurs, or -1
 * if s1 contains no characters from s2.
 */

#include <stdio.h>

#define MAXSTR 20

void readstr(char str[]);
int any(char s1[], char s2[]);

int main(void)
{
    char s1[MAXSTR], s2[MAXSTR];

    printf("Enter first string: ");
    readstr(s1);
    printf("Enter second string: ");
    readstr(s2);
    printf("Index of first character from second string: %d\n", any(s1, s2));

    return 0;
}

/* saves next line from stdin to provided string */
void readstr(char str[])
{
    int i, c;

    for (i = 0; i < MAXSTR - 1 && (c = getchar()) != '\n' && c != EOF; i++)
        str[i] = c;
    str[i] = '\0';
}

int any(char s1[], char s2[])
{
    int i, j;

    for (i = 0; i < MAXSTR - 1 && s2[i] != '\0'; i++)
        for (j = 0; j < MAXSTR - 1 && s1[j] != '\0'; j++)
            if (s1[j] == s2[i])
                return j;
    return -1;
}
