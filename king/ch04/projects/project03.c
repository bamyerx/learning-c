/*
 * Project 3 from chapter 4 of C Programming by K.N. King.
 *
 * Asks the user to enter a three-digit number, then prints the number with
 * its digits reversed.
 *
 * Note: must reverse without using arithmetic.
 */

#include <stdio.h>

int main(void)
{
    int i1, i2, i3;

    printf("Enter a three-digit number: ");
    scanf("%1d%1d%1d", &i1, &i2, &i3);

    printf("The reversal is: %d%d%d\n", i3, i2, i1);

    return 0;
}
