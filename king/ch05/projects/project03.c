/*
 * Project 3 from Chapter 5 from King: Modify the broker.c program of Section
 * 5.2 by making both of the following changes:
 * (a) Ask the user to enter the number of shares and the price per share,
 *     instead of the value of the trade.
 * (b) Add statements that compute the commission charged by a rival broker ($33
 *     plus 3 cents per share for fewer than 2000 shares; $33 plus 2 cents per
 *     share for 2000 shares or more). Display the rival's commission as well as
 *     the commission charged by the original broker.
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
