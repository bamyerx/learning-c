/*
 * Exercises 2-4 from K&R: Write an alternative version of squeeze(s1,s2) that
 * deletes each character in s1 that matches any character in the string s2.
 */

#include <stdio.h>

#define MAXSTR 20

void squeeze(char s1[], char s2[]);

int main(void)
{
    int i, c;
    char s1[MAXSTR], s2[MAXSTR];
    printf("Enter first string: ");
    for (i = 0; i < MAXSTR - 1 && (c = getchar()) != '\n'; i++)
        s1[i] = c;
    printf("Enter second string: ");
    for (i = 0; i < MAXSTR - 1 && (c = getchar()) != '\n'; i++)
        s2[i] = c;
    squeeze(s1, s2);
    printf("First string after squeezing: %s\n", s1);

    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j, k;

    for (i = 0; s2[i] != '\0'; i++)
        for (j = k = 0; s1[j] != '\0'; j++)
            if (s1[j] != s2[i])
                s1[k++] = s1[j];
    s1[k] = '\0';
}
