/*
 * Project 10 from Chapter 6 of King: Programming Project 9 in Chapter 5 asked
 * you to write a program that determines which of two dates come earlier on the
 * calendar. Generalize the program so that the user may enter any number of
 * dates. The user will enter 0/0/0 to indicate that no more dates will be
 * entered:
 *
 *     Enter a date (mm/dd/yy): 3/6/08
 *     Enter a date (mm/dd/yy): 5/17/07
 *     Enter a date (mm/dd/yy): 6/3/07
 *     Enter a date (mm/dd/yy): 0/0/0
 *     5/17/07 is the earliest date
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
