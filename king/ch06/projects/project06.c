/*
 * Project 6 from chapter 6 of C Programming by K.N. King.
 *
 * Prompts the user to enter a number n, then prints all even squares between
 * 1 and n.
 */

#include <stdio.h>

int main(void)
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    for (int i = 2; i * i <= n; i += 2) {
        printf("%d\n", i * i);
    }

    return 0;
}
