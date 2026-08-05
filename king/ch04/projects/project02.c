/*
 * Project 2 from Chapter 4 of King: Extend the program in Programming Project 1
 * to handle three-digit numbers.
 */

#include <stdio.h>

int main(void)
{
    int n;

    printf("Enter a three-digit number: ");
    scanf("%3d", &n);

    printf("The reversal is: %d%d%d\n", n % 10, (n / 10) % 10, n / 100);

    return 0;
}
