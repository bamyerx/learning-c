/*
 * Project 4 from Chapter 4 of King: Write a program that reads an integer
 * entered by the user and displays it in octal (base 8):
 *
 *     Enter a number between 0 and 32767: 1953
 *     In octal, your number is: 03641
 *
 * The output should be displayed using five digits, even if fewer digits are
 * sufficient.
 */

#include <stdio.h>

int main(void)
{
    int n, i0, i1, i2, i3, i4;

    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &n);

    i4 = n / (8 * 8 * 8 * 8);
    n -= i4 * (8 * 8 * 8 * 8);
    i3 = n / (8 * 8 * 8);
    n -= i3 * (8 * 8 * 8);
    i2 = n / (8 * 8);
    n -= i2 * (8 * 8);
    i1 = n / 8;
    i0 = n % 8;

    printf("In octal, your number is: %d%d%d%d%d\n", i4, i3, i2, i1, i0);

    return 0;
}
