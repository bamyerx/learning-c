/*
 * Project 4 from Chapter 2 of King: Write a program that asks the user to enter
 * a dollar-and-cents amount, then displays the amount with 5% tax added:
 *
 *     Enter an amount: 100.00
 *     With tax added: $105.00
 */

#include <stdio.h>

#define TAX_RATE 0.05f

int main(void)
{
	float amount, amount_with_tax;

	printf("Enter an amount: ");
	scanf("%f", &amount);

	amount_with_tax = amount * (1.0f + TAX_RATE);

	printf("With tax added: $%.2f\n", amount_with_tax);

	return 0;
}
