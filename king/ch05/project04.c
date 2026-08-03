/*
 * Project 4 from chapter 5 of C Programming by K.N. King.
 *
 * Asks the user to enter a wind speed (in knots), then displays the
 * corresponding description from a simplified Beaufort scale.
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
