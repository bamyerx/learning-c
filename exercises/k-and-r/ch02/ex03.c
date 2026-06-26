/*
 * Exercise 2-3 from K&R: Write a function htoi(s), which converts a string of
 * hexadecimal digits (including an optional 0x or 0X) into its equivalent
 * integer value. The allowable digits are 0 through 9, a through f, and A
 * through F.
 */

#include <stdio.h>

#define MAX 100

int htoi(char h[]);

int main(void)
{
    int c, i;
    char h[MAX];

    printf("Enter a hexadecimal number: ");
    for (i = 0; i < MAX && (c = getchar()) != '\n'; ++i)
        h[i] = c;

    printf("Equivalent integer value: %d\n", htoi(h));

    return 0;
}

/* htof: converts h to integer */
int htoi(char h[])
{
    int i, n;

    i = 0;
    n = 0;
    if (h[0] == '0' && (h[1] == 'x' || h[1] == 'X'))
        i = 2;
    while (h[i] >= '0' && h[i] <= '9' ||
           h[i] >= 'A' && h[i] <= 'F' ||
           h[i] >= 'a' && h[i] <= 'f') {
        if (h[i] >= '0' && h[i] <= '9')
            n = 16 * n + (h[i] - '0');
        else if (h[i] >= 'A' && h[i] <= 'F')
            n = 16 * n + (h[i] - 'A' + 10);
        else if (h[i] >= 'a' && h[i] <= 'f')
            n = 16 * n + (h[i] - 'a' + 10);
        ++i;
    }
    return n;
}
