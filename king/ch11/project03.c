/*
 * Project 3 from Chapter 6 King: Modify Programming Project 3 so that it
 * includes the following functions:
 *
 *      void reduce(int numerator, int denominator,
 *                  int *reduced_numerator,
 *                  int *reduced_denominator);
 *
 *  numerator and denominator are the numerator and denominator of a fraction.
 *  reduced_numerator and reduced_denominator are pointers to variables in which
 *  the functions will store the numerator and denominator of the fraction once
 *  it has been reduced to lowest terms.
 */

#include <stdio.h>

void reduce(int, int, int *, int *);

int main(void)
{
    int num, denom, reduced_num, reduced_denom;

    printf("Enter a fraction: ");
    scanf("%d / %d", &num, &denom);

    reduce(num, denom, &reduced_num, &reduced_denom);
    printf("In lowest terms: %d/%d\n", reduced_num, reduced_denom);

    return 0;
}

void reduce(int numerator, int denominator, 
            int *reduced_numerator, int *reduced_denominator)
{
    int n = numerator, m = denominator, r;
    while (n != 0) {
        r = m % n;
        m = n;
        n = r;
    }
    *reduced_numerator = numerator / m;
    *reduced_denominator = denominator / m;
}
