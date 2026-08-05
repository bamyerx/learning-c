/*
 * Project 1 from Chapter 4 of King: Write a program that asks the user to enter
 * a two-digit number, then prints the number with its digits reversed. A
 * session with the program should have the following appearance:
 *
 *     Enter a two-digit number: 28
 *     The reversal is: 82
 *
 * Read the number using %d, then break it into two digits.
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
