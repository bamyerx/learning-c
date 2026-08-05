/*
 * Project 5 from Chapter 2 of King: Write a program that asks the user to enter
 * a value of x and then displays the value of the following polynomial:
 *
 *     3x^5+2x^4-5x^3-x^2+7x-6
 */

#include <stdio.h>

int main(void)
{
    float x, fx;

    printf("Enter a value for x: ");
    scanf("%f", &x);

    fx = 3 * x * x * x * x * x
         + 2 * x * x * x * x
         - 5 * x * x * x
         - x * x
         + 7 * x
         - 6;

    printf("f(x) = %.2f\n", fx);

    return 0;
}
