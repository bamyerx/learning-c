/*
 * Project 1 from chapter 6 of C Programming by K.N. King.
 *
 * Finds the largest in a series of numbers entered by the user.
 *
 * This program prompts the user to enter numbers one by one. When the user
 * enters 0 or a negative number, the program displays the largest nonnegative
 * number entered.
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
