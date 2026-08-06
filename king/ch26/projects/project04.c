/*
 * Project 4 from Chapter 26 of King: Write a program that prompts the user for
 * a date (month, day, and year) and an integer n, then prints the date that's
 * n days later.
 */

#include <stdio.h>
#include <time.h>

int main(void)
{
	int n;
	struct tm t = {0};
	t.tm_isdst = -1;

	printf("Enter date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &t.tm_mon, &t.tm_mday, &t.tm_year);
	t.tm_mon  -= 1;
	t.tm_year -= 1900;
	printf("Enter number of days: ");
	scanf("%d", &n);

	t.tm_mday += n;
	mktime(&t);
	printf("%d days later, it will be %d/%d/%d\n", n, 
		   t.tm_mon + 1, t.tm_mday, t.tm_year + 1900);

	return 0;
}
