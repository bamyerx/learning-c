/*
 * Project 1 from chapter 3 of C Programming by K.N. King.
 *
 * Accepts a date from the user in the form mm/dd/yyyy and then displays it in
 * the form yyyymmdd.
 */

#include <stdio.h>

int main(void)
{
    int year, month, day;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    printf("You entered the date %.4d%.2d%.2d\n", year, month, day);

    return 0;
}
