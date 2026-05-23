/*
 * Project 8 from chapter 6 of C Programming by K.N. King.
 *
 * Prints a one-month calendar. The user specifies the number of days in the
 * month and the day of the week on which the month begins.
 */

#include <stdio.h>

int main(void)
{
    int days_in_month, starting_day;

    printf("Enter number of days in month: ");
    scanf("%d", &days_in_month);
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &starting_day);

    if (starting_day < 1 || starting_day > 7) {
        printf("Invalid starting day of the week\n");
        return 0;
    }
    for (int i = 1; i < starting_day; i++) {
        printf("   ");
    }
    for (int i = 1; i <= days_in_month; i++) {
        printf("%3d", i);
        if((starting_day + i - 1) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");

    return 0;
}
