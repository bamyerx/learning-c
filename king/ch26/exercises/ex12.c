/*
 * Exercise 12 from Chapter 26 of King: Write a function that, when passed a
 * year, returns a time_t value representing 12:00 a.m. on the first day of that
 * year.
 */

#include <time.h>

time_t get_first_midnight(int year)
{
	struct tm t = {0};

	t.tm_mday = 1;
	t.tm_year = year - 1900;
	t.tm_isdst = -1;

	return mktime(&t);
}
