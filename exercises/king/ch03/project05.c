/*
 * Project 5 of chapter 3 of C Programming by K.N. King.
 *
 * Asks the user to enter the numbers from 1 to 16 in any order and then
 * displays the numbers in a 4 by 4 arrangement, followed by the sums of
 * the rows, columns, and diagonals.
 *
 */

#include <stdio.h>

int main(void)
{
    int a11, a12, a13, a14,
        a21, a22, a23, a24,
        a31, a32, a33, a34,
        a41, a42, a43, a44;

    printf("Enter the numbers from 1 to 16 in any order:\n");
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        &a11, &a12, &a13, &a14,
        &a21, &a22, &a23, &a24,
        &a31, &a32, &a33, &a34,
        &a41, &a42, &a43, &a44
    );

    printf("%2d %2d %2d %2d\n", a11, a12, a13, a14);
    printf("%2d %2d %2d %2d\n", a21, a22, a23, a24);
    printf("%2d %2d %2d %2d\n", a31, a32, a33, a34);
    printf("%2d %2d %2d %2d\n", a41, a42, a43, a44);
    printf("Row sums: %d %d %d %d\n",
        a11 + a12 + a13 + a14,
        a21 + a22 + a23 + a24,
        a31 + a32 + a33 + a34,
        a41 + a42 + a43 + a44
    );
    printf("Column sums: %d %d %d %d\n",
        a11 + a21 + a31 + a41,
        a12 + a22 + a32 + a42,
        a13 + a23 + a33 + a43,
        a14 + a24 + a34 + a44
    );
    printf("Diagonal sums: %d %d\n",
        a11 + a22 + a33 + a44,
        a14 + a23 + a32 + a41
    );

    return 0;
}
