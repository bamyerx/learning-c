/*
 * Project 12 from chapter 6 of C Programming by K.N. King.
 *
 * Approximates e (Euler's Number) by computing the value of
 *             1 + 1/1! + 1/2! + 1/3! + ... + 1/n!
 * until the current term becomes less than epsilon, where epsilon is a small
 * floating-point number entered by the user.
 */

#include <stdio.h>

int main(void)
{
    float e = 1.0f, f = 1.0f, term = 1.0f, epsilon;

    printf("Provide a value for epsilon: ");
    scanf("%f", &epsilon);

    int i = 1;
    while (term >= epsilon) {
        f *= i;
        term = 1.0f / f;
        if (term >= epsilon) {
            e += term;
        }
        i++;
    }
    printf("e = %g\n", e);

    return 0;
}
