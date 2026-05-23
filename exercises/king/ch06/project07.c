/*
 * Project 7 from chapter 6 of C Programming by K.N. King.
 *
 * Prints a table of squares using an odd method.
 */

#include <stdio.h>

int main(void)
{
    int n, odd, square;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    odd = 3;
    for (int i = 1, square = 1; i <= n; odd += 2, ++i) {
        printf("%10d%10d\n", i, square);
        square += odd;
    }

    return 0;
}
