/*
 * Project 5 of Chapter 3 of King: Write a program that asks the user to enter
 * the numbers from 1 to 16 (in any order) and then displays the numbers in a 4
 * by 4 arrangement, followed by the sums of the rows, columns, and diagonals:
 *
 *     Enter the numbers from 1 to 16 in any order:
 *     16 3 2 13 5 10 11 8 9 6 77 12 4 15 14 1
 *     
 *     16  3  2 13
 *      5 10 11  8
 *      9  6  7 12
 *      4 15 14  1
 *
 *      Row sums: 34 34 34 34
 *      Column sums: 34 34 34 34
 *      Diagonal sums: 34 34 34 34
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
