/*
 * Project 10 from Chapter 13 of King: Modify Programming Project 11 from
 * Chapter 7 so that it includes the following function:
 *
 *      void reverse_name(char *name);
 *
 * The function expects name to point to a string containing a first name
 * followed by a last name. It modifies the string so that the last name comes
 * first, followed by a comma, a space, the first initial, and a period. The
 * original string may contain extra spaces before the first name, between the
 * first and last names, and after the last name.
 */

#include <stdio.h>

#define MAXNAME 100

void reverse_name(char *);
int readline(char [], int);

int main(void)
{
    char name[MAXNAME+1];

    printf("Enter a first and last name: ");
    readline(name, MAXNAME);
    reverse_name(name);
    printf("%s\n", name);

    return 0;
}

void reverse_name(char *name)
{
    char first_initial, temp[MAXNAME+1];
    int i = 0, j = 0;

    while (name[i] == ' ')
        i++;
    first_initial = name[i];
    while (name[i] != ' ')
        i++;
    while (name[i] == ' ')
        i++;
    while (name[i] != '\0' && name[i] != ' ') {
        temp[j++] = name[i++];
    }
    temp[j] = '\0';
    sprintf(name, "%s, %c.", temp, first_initial);
}

int readline(char line[], int len)
{
    int c, i = 0;

    while ((c = getchar()) != '\n')
        if (i < len)
            line[i++] = c;
    line[i] = '\0';
    return i;
}
