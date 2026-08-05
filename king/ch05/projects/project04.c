/*
 * Project 4 from Chapter 5 of King: Here's a simplified version of the Beaufort
 * scale, which is used to estimate wind force:
 *
 *     Speed (knots)    Description
 *     Less than 1      Calm
 *     1-3              Light air
 *     4-27             Breeze
 *     28-47            Gale
 *     48-63            Storm
 *     Above 63         Hurricane
 *
 * Write a program that asks the user to enter a wind speed (in knots), then
 * displays the corresponding description.
 */

#include <stdio.h>

int main(void)
{
    int speed;

    printf("Enter the wind speed in knots: ");
    scanf("%d", &speed);

    printf("Wind force: ");
    if (speed > 63) {
        printf("Hurricane\n");
    } else if (speed >= 48) {
        printf("Storm\n");
    } else if (speed >= 28) {
        printf("Gale\n");
    } else if (speed >= 4) {
        printf("Breeze\n");
    } else if (speed >= 1) {
        printf("Light air\n");
    } else {
        printf("Calm\n");
    }

    return 0;
}
