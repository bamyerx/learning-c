/*
 * Project 5 of Chapter 4 of King: Rewrite the upc.c program of Section 4.1 so
 * that the user enters 11 digits at one time, instead of entering one digit,
 * then five digits, and then another five digits.
 *
 *     Enter the first 11 digits of a UPC: 01380015173
 *     Check digit: 5
 */

#include <stdio.h>

int main(void)
{
    int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, sum1, sum2, check_digit;

    printf("Enter the first 11 digits of a UPC: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",
        &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9, &i10, &i11);

    sum1 = i1 + i3 + i5 + i7 + i9 + i11;
    sum2 = i2 + i4 + i6 + i8 + i10;
    check_digit = 9 - ((3 * sum1 + sum2) - 1) % 10;

    printf("Check digit: %d\n", check_digit);

    return 0;
}
