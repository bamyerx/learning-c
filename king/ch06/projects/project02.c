/*
 * Project 2 from Chapter 6 of King: Write a program that asks the user to enter
 * two integers, then calculates and displays their greatest common divisor:
 *
 *     Enter two integers: 12 28
 *     Greatest common divisor: 4
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
