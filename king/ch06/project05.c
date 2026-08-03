/*
 * Project 5 from chapter 6 of C Programming by K.N. King.
 *
 * Asks the user to enter a number, then prints the number with its digits
 * reversed.
 *
 */

#include <stdio.h>

int main(void)
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("The reversal is: ");
    do {
        printf("%d", n % 10);
        n /= 10;
    } while (n > 0);
    printf("\n");

    return 0;
}
