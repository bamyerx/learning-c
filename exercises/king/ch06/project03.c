/*
 * Project 3 from chapter 6 of C Programming by K.N. King.
 *
 * Asks the user to enter a fraction, then reduces the fraction to lowest
 * terms.
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
