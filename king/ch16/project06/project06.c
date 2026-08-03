/*
 * Project 6 from Chapter 16 of King: Modify Programming Project 9 from Chapter
 * 5 so that each date entered by the user is stored in a date structure.
 * Incorporate the compare_dates function of Exercise 5 into your program.
 */

#include <stdio.h>

struct date {
	int month, day, year;
};
int day_of_year(struct date);
int compare_dates(struct date, struct date);

int main(void)
{
    struct date d1, d2;
	int result;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &d1.month, &d1.day, &d1.year);
	if (d1.month < 1 || d1.month > 12 || 
		d1.day < 1 || d1.day > 31 || d1.year < 1) {
		printf("Invalid date\n");
		return 0;
	}
    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d", &d2.month, &d2.day, &d2.year);
	if (d2.month < 1 || d2.month > 12 || 
		d2.day < 1 || d2.day > 31 || d2.year < 1) {
		printf("Invalid date\n");
		return 0;
	}
	result = compare_dates(d1, d2);
    if (result < 1) {
        printf("%d/%d/%02d is earlier than %d/%d/%02d\n", 
				d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);
    } else if (result > 1) {
        printf("%d/%d/%02d is earlier than %d/%d/%02d\n",
				d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);
    } else {
        printf("Please enter two different dates.\n");
    }

    return 0;
}

int day_of_year(struct date d)
{
	int i;
	int leap = (d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0;
	int months[] = {31, 28 + leap, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	for (i = 0; d.month > i + 1; i++) {
		d.day += months[i];
		d.month -= months[i];
	}
	return d.day;
}

int compare_dates(struct date d1, struct date d2)
{
	int diff;

	diff = day_of_year(d1) - day_of_year(d2);
	if (diff < 0)
		return -1;
	else if (diff > 0)
		return 1;
	else
		return diff;
}
