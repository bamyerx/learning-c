/*
 * Project 16 from Chapter 13 of King: Modify Programming Project 1 from Chapter
 * 12 so that it includes the following function:
 *
 *      void reverse(char *message);
 *
 * The function reverses the string pointed to by message.
 */

#include <stdio.h>

#define MAXMSG 100

void reverse(char *);

int main(void)
{
    char msg[MAXMSG];
    int c, i = 0;

    printf("Enter a message: ");
    while ((c = getchar()) != '\n')
        if (i < MAXMSG)
            msg[i++] = c;
    msg[i] = '\0';
    printf("%s\n", msg);
    reverse(msg);
    printf("Reversal is: %s\n", msg);

    return 0;
}

void reverse(char *message)
{
    char *left, *right, temp;

    left = message;
    while (*message++)
        ;
    right = message - 2;
    while (left < right) {
        temp = *left;
        *left++ = *right;
        *right-- = temp;
    }
}
