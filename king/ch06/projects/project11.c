/*
 * Project 11 from Chapter 6 of King: The value of the mathematical constant e
 * can be expressed as an infinite series:
 *
 *     e = 1 + 1/1! + 1/2! + 1/3! + ...
 *
 * Write a program that approximates e by computing the value of
 *
 *     1 + 1/1! + 1/2! + 1/3! + ... + 1/n!
 *
 * where n is an integer entered by the user.
 */

#include <stdio.h>

int main(void)
{
    int n;
    float e = 1, f = 1;

    printf("Provide a value for n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        f *= i;
        e += 1.0f / f;
    }
    printf("e = %g\n", e);

    return 0;
}
