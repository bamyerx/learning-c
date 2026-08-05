/*
 * Project 3 from chapter 5 of C Programming by K.N. King.
 *
 * Calculates a broker's commission.
 */

#include <stdio.h>

int main(void)
{
    float shares, price, value, commission, rival_commission;

    printf("Enter the number of shares: ");
    scanf("%f", &shares);
    printf("Enter the price per share: ");
    scanf("%f", &price);

    value = shares * price;

    if (value < 2500.00f) {
        commission = 30.00f + value * 0.017f;
    } else if (value < 6250.00f) {
        commission = 56.00f + value * 0.0066f;
    } else if (value < 20000.00f) {
        commission = 76.0f + value * 0.0034f;
    } else if (value < 50000.00f) {
        commission = 100.0f + value * 0.0022f;
    } else if (value < 500000.00f) {
        commission = 155.0f + value * 0.0011f;
    } else {
        commission = 255.0f + value * 0.0009f;
    }

    if (commission < 39.00f) {
        commission = 39.00f;
    }

    if (shares < 2000) {
        rival_commission = 33.00f + 0.03f * shares;
    } else {
        rival_commission = 33.00f + 0.02f * shares;
    }

    printf("Commission: $%.2f\tRival Commission: $%.2f\n",
        commission, rival_commission);

    return 0;
}
