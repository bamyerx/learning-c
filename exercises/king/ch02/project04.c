/*
 * Project 4 from chapter 2 of C Programming by K.N. King.
 *
 * Compute a dollar amount with tax added.
 */

#include <stdio.h>

#define TAX_RATE 0.05f

int main(void)
{
    float amount, amount_with_tax;

    printf("Enter an amount: ");
    scanf("%f", &amount);

    amount_with_tax = amount * (1 + TAX_RATE);

    printf("With tax added: $%.2f\n", amount_with_tax);

    return 0;
}
