/*
 * Project 6 from Chapter 2 of King: Modify the program of Programming Project 5
 * so that the polynomial is evaluated using the following formula:
 *
 *     ((((3x^5)x - 5)x - 1)x + 7)x - 6
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
