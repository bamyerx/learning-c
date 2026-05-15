/*
 * Project #8 from chapter 2 of C Programming by K.N. King.
 *
 * Calculates the remaining balance on a loan after the first, second, and third
 * payments.
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

    balance = balance - payment + balance * monthly_rate;
    printf("Balance remaining after first payment: $%.2f\n", balance);
    balance = balance - payment + balance * monthly_rate;
    printf("Balance remaining after second payment $%.2f\n", balance);
    balance = balance - payment + balance * monthly_rate;
    printf("Balance remaining after third payment $%.2f\n", balance);

    return 0;
}
