/*
 * Project 2 from chapter 5 of C Programming by K.N. King.
 *
 * Asks the user for a 24-hour time, then displays the time in 12-hour form.
 */

#include <stdio.h>

int main(void)
{
    int hour, minute;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minute);
    printf("Equivalent 12-hour time: ");
    if (hour % 12 == 0) {
        printf("12:%02d ", minute);
    } else {
        printf("%d:%02d ", hour % 12, minute);
    }
    if (hour > 11 && hour < 24) {
        printf("PM\n");
    } else {
        printf("AM\n");
    }

    return 0;
}
