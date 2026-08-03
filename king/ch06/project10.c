/*
 * Project 10 from chapter 6 C Programming by K.N. King.
 *
 * Prompts the user to enter dates and then indicates which date comes earliest
 * on the calendar. The user can enter 0/0/0 to indicate that no more dates
 * will be entered.
 */

#include <stdio.h>

int main(void)
{
    int m, d, y, min_m, min_d, min_y, date_calc, min_date_calc;

    printf("Enter a date (mm/dd/yy): ");
    scanf("%d/%d/%d", &min_m, &min_d, &min_y);
    min_date_calc = min_y * 10000 + min_m * 100 + min_d;

    for (;;) {
        printf("Enter a date (mm/dd/yy): ");
        scanf("%d/%d/%d", &m, &d, &y);
        date_calc = y * 10000 + m * 100 + d;

        if (date_calc == 0) {
            break;
        }

        if (date_calc < min_date_calc) {
            min_m = m;
            min_d = d;
            min_y = y;
        }
    }
    printf("%d/%d/%02d is the earliest date\n", min_m, min_d, min_y);

    return 0;
}
