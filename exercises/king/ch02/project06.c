/*
 * Project #6 from chapter 2 of C Programming by K.N. King.
 *
 * Displays the value of 3x^5+2x^4-5x^3-x^2+7x-6 for a user-defined value of x
 * using Horner's rule for evaluation.
 */

#include <stdio.h>

int main(void)
{
    float x, fx;

    printf("Enter a value for x: ");
    scanf("%f", &x);

    fx = ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;

    printf("f(x) = %.2f\n", fx);

    return 0;
}
