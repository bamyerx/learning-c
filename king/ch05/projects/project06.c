/*
 * Project 6 from Chapter 5 of King: Modify the upc.c program of Section 4.1 so
 * that it checks whether a UPC is valid. After the user enters a UPC, the pro-
 * gram will display either VALID or NOT VALID.
 */

#include <stdio.h>

int main(void)
{
    int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12,
        sum1, sum2, check_digit;

    printf("Enter an UPC: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",
        &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9, &i10, &i11, &i12);

    sum1 = i1 + i3 + i5 + i7 + i9 + i11;
    sum2 = i2 + i4 + i6 + i8 + i10;
    check_digit = 9 - ((3 * sum1 + sum2) - 1) % 10;

    if (i12 == check_digit) {
        printf("VALID\n");
    } else {
        printf("NOT VALID\n");
    }

    return 0;
}
