/*
 * Project 2 from chapter 4 of C Programming by K.N. King.
 *
 * Asks the user to enter a three-digit number, then prints the number with
 * its digits reversed.
 *
 * Note: must read the number using %d, then break it into three digits.
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
