/*
 * Project 1 from chapter 4 of C Programming by K.N. King.
 *
 * Asks the user to enter a two-digit number, then prints the number with its
 * digits reversed.
 *
 * Note: must read the number using %d, then break it into two digits.
 */

#include <stdio.h>

int main(void)
{
    int n;

    printf("Enter a two-digit number: ");
    scanf("%2d", &n);

    printf("The reversal is: %d%d\n", n % 10, n / 10);

    return 0;
}
