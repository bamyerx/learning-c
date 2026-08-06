/*
 * Project 5 from Chapter 26 of King: Write a program that prompts the user to
 * enter two dates, then prints the difference between them, measured in days.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SECS_IN_DAY 86400

int main(void)
{
	struct tm t1 = {0};
	struct tm t2 = {0};
	int diff;

	t1.tm_isdst = t2.tm_isdst = -1;
	printf("Enter first date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &t1.tm_mon, &t1.tm_mday, &t1.tm_year);
	t1.tm_mon -= 1;
	t1.tm_year -= 1900;
	printf("Enter second date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &t2.tm_mon, &t2.tm_mday, &t2.tm_year);
	t2.tm_mon -= 1;
	t2.tm_year -= 1900;

	diff = abs((int) difftime(mktime(&t1), mktime(&t2)));
	printf("Days difference between two dates: %d\n", diff / SECS_IN_DAY);

	return 0;
}
