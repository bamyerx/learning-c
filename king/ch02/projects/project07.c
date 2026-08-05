/*
 * Project 7 from Chapter 2 of King: Write a program that asks the user to enter
 * a U.S. dollar amount and then shows how to pay that amount using the smallest
 * number of $20, $10, $5, and $1 bills:
 *
 *     Enter a dollar amount: 93
 *
 *     $20 bills: 4
 *     $10 bills: 1
 *      $5 bills: 0
 *      $1 bills: 3
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
