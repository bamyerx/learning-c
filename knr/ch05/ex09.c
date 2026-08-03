/*
 * Exercise 5-9 from K&R: Rewrite the routines day_of_year and month_day with
 * pointers instead of indexing.
 */

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
	int leap;
	char (*p)[13], *q;
	
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	p = daytab + leap;
	q = *p;
	if (year < 1 || 
		month < 1 || month > 12 || 
		day < 1 || day > *(q + month)) {
		return 0;
	}
	while (month--)
		day += *q++;
	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int leap;
	char (*p)[13], *q;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	p = daytab + leap;
	q = *p;
	if (yearday < 1 || yearday > 365 + leap) {
		*pmonth = *pday = 0;
		return;
	}
	while (yearday > *q)
		yearday -= *q++;
	*pmonth = q - *p;
	*pday = yearday;
}
