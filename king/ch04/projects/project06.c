/*
 * Project 6 of Chapter 4 of King: Modify the upc.c program of Section 4.1 so
 * that it calculates the check digit for an European Article Number (EAN). The
 * user will enter the first 12 digits of the EAN as a single number:
 *
 *     Enter the first 12 digits of an EAN: 869148426000
 *     Check digit: 8
 */

#include <stdio.h>

int main(void)
{
    int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12,sum1, sum2, check_digit;

    printf("Enter the first 12 digits of a EAN: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",
        &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9, &i10, &i11, &i12);

    sum1 = i2 + i4 + i6 + i8 + i10 + i12;
    sum2 = i1 + i3 + i5 + i7 + i9 + i11;
    check_digit = 9 - ((3 * sum1 + sum2) - 1) % 10;

    printf("Check digit: %d\n", check_digit);

    return 0;
}
