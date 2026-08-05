/*
 * Project 9 from Chapter 6 of King: Programming Project 8 in Chapter 2 asked
 * you to write a program that calculates the remaining balance on a loan after
 * the first, second, and third monthly payments. Modify the program so that it
 * also asks the user to enter the number of payments and then displays the
 * balance remaining after each of these payments.
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
