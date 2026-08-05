/*
 * Project 3 from Chapter 4 of King: Rewrite the program in Programming Project
 * 2 so that it prints the reversal of a three-digit number without using arith-
 * metic to split the number into digits.
 */

#include <stdio.h>

int main(void)
{
    int i1, i2, i3;

    printf("Enter a three-digit number: ");
    scanf("%1d%1d%1d", &i1, &i2, &i3);

    printf("The reversal is: %d%d%d\n", i3, i2, i1);

    return 0;
}
