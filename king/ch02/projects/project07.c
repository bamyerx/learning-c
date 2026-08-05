/*
 * Project #7 from chapter 2 of C Programming by K.N. King.
 *
 * Computes the smallest number of bills used to pay a dollar amount.
 */

#include <stdio.h>

int main(void)
{
    int amount, twenties, tens, fives, ones;

    printf("Enter a dollar amount: ");
    scanf("%d", &amount);

    twenties = amount / 20;
    amount = amount - 20 * twenties;
    tens = amount / 10;
    amount = amount - 10 * tens;
    fives = amount / 5;
    amount = amount - 5 * fives;
    ones = amount;

    printf("$20 bills: %d\n", twenties);
    printf("$10 bills: %d\n", tens);
    printf(" $5 bills: %d\n", fives);
    printf(" $1 bills: %d\n", ones);

    return 0;
}
