/*
 * Project 3 from Chapter 6 of King: Write a program that asks the user to enter
 * a fraction, then reduces the fraction to lowest common terms:
 *
 *     Enter a fraction: 6/12
 *     In lowest terms: 1/2
 */

#include <stdio.h>

int main(void)
{
    int num, denom;

    printf("Enter a fraction: ");
    scanf("%d / %d", &num, &denom);

    int n = num, m = denom, r;
    while (n != 0) {
        r = m % n;
        m = n;
        n = r;
    }
    printf("In lowest terms: %d/%d\n", num / m, denom / m);

    return 0;
}
