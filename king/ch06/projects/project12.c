/*
 * Project 12 from Chapter 6 of King: Modify programming Project 11 so that the
 * program continues adding terms until the current term becomes less than 
 * epsilon, where epsilon is a small (floating-point) number entered by the
 * user.
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
