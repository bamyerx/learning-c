/*
 * Project 1 from Chapter 6 of King: Write a program that finds the largest in a
 * series of numbers entered by the user. When the user enters 0 or a negative
 * number, the program must display the largest nonnegative number entered:
 *
 *     Enter a number: 60
 *     Enter a number 38.3
 *     Enter a number: 4.89
 *     Enter a number: 100.62
 *     Enter a number: 75.2295
 *     Enter a number: 0
 *
 *     The largest number entered was 100.62
 *
 * Notice that the numbers aren't necessarily integers.
 */

#include <stdio.h>

int main(void)
{
    float f, max = 0.0f;

    for (;;) {
        printf("Enter a number: ");
        scanf("%f", &f);
        if (f > max) {
            max = f;
        }
        if (f <= 0) {
            break;
        }
    }
    printf("\nThe largest number entered was %g\n", max);

    return 0;
}
