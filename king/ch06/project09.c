/*
 * Project 9 from chapter 6 of C Programming by K.N. King.
 *
 * Calculates the remaining balance on a loan after a given number of payments.
 */

#include <stdio.h>

int main(void)
{
    float balance, rate, payment, monthly_rate;
    int n;

    printf("Enter amount of loan: ");
    scanf("%f", &balance);
    printf("Enter interest rate: ");
    scanf("%f", &rate);
    printf("Enter monthly payment: ");
    scanf("%f", &payment);
    printf("Enter the number of payments: ");
    scanf("%d", &n);

    monthly_rate = (rate / 100) / 12;

    for (int i = 1; i <= n; i++) {
        balance += balance * monthly_rate - payment;
        printf("Balance remaining after %d payments: $%.2f\n", i, balance);
    }

    return 0;
}
