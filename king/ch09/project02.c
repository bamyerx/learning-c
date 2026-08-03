/*
 * Project 2 from Chapter 9 of King: Modify Programming Project 5 of Chapter 5 
 * so that it uses a function to compute the amount of income tax. When passed
 * an amount of taxable income, the function will return the tax due.
 */

#include <stdio.h>

float get_tax(float income);

int main(void)
{
    float income;

    printf("Enter your taxable income: ");
    scanf("%f", &income);
    printf("Tax due: $%.2f\n", get_tax(income));

    return 0;
}

float get_tax(float income)
{
   if (income <= 750.00f) {
        return income * 0.01f;
    } else if (income <= 2250.00f) {
        return 7.50f + (income - 750.00f) * 0.02f;
    } else if (income <= 3750.00f) {
        return 37.50f + (income - 2250.00f) * 0.03f;
    } else if (income <= 5250.00f) {
        return 82.50f + (income - 3750.00f) * 0.04f;
    } else if (income <= 7000.00f) {
        return 142.50f + (income - 5250.00f) * 0.05f;
    } else {
        return 230.00f + (income - 7000.00f) * 0.06f;
    }
}
