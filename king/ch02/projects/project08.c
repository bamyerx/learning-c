/*
 * Project 8 from Chapter 2 of King: Write a program that calculates the
 * remaining balance on a loan after the first, second, and third monthly
 * payments:
 *
 *     Enter amount of loan: 20000.00
 *     Enter interest rate: 6.0
 *     Enter monthly payment: 386.66
 *
 *     Balance remaining after first payment: $19713.34
 *     Balance remaining after second payment: $19425.25
 *     Balance remaining after third payment: $19135.71
 *
 * Display each balance with two digits after the decimal point.
 */

#include <stdio.h>

int main(void)
{
    float balance, rate, payment, monthly_rate;

    printf("Enter amount of loan: ");
    scanf("%f", &balance);
    printf("Enter interest rate: ");
    scanf("%f", &rate);
    printf("Enter monthly payment: ");
    scanf("%f", &payment);

    monthly_rate = (rate / 100) / 12;

    balance = balance * (1.0f + monthly_rate) - payment;
    printf("Balance remaining after first payment: $%.2f\n", balance);
    balance = balance * (1.0f + monthly_rate) - payment;
    printf("Balance remaining after second payment: $%.2f\n", balance);
    balance = balance * (1.0f + monthly_rate) - payment;
    printf("Balance remaining after third payment: $%.2f\n", balance);

    return 0;
}
