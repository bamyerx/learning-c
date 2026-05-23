/*
 * Project 2 from chapter 6 of C Programming by K.N. King.
 *
 * Asks the user to enter two integers, then calculates and displays their
 * greatest common divisor.
 */

#include <stdio.h>

int main(void)
{
    int m, n, r;

    printf("Enter two integers: ");
    scanf("%d %d", &m, &n);

    while (n != 0) {
        r = m % n;
        m = n;
        n = r;
    }

    printf("Greatest common divisor: %d\n", m);

    return 0;
}
