/*
 * Project 5 from Chapter 6 of King: Programming Project 1 in Chapter 4 asked
 * you to write a program that displays a two-digit number with its digits
 * reversed. Generalize the program so that the number can have one, two, three,
 * or more digits.
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
