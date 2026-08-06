/*
 * Project 3 from Chapter 26 of King: Write a program that uses the clock func-
 * tion to measure how long it takes qsort to sort an array of 1000 integers
 * that are originally in reverse order. Run the program for arrays of 10000 and
 * 100000 integers as well.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

int intcmp(const void *, const void *);

int main(void)
{
	int i, a[N];
	clock_t t;

	for (i = N - 1; i >= 0; i--)
		a[i] = i;
	t = clock();
	qsort(a, N, sizeof(a[0]), intcmp);
	printf("Time to sort: %g ms\n", 1000 * (clock() - t) / (double) CLOCKS_PER_SEC);

	return 0;
}

int intcmp(const void *a, const void *b)
{
	int x = *(const int *) a;
	int y = *(const int *) b;

	return (x > y) - (x < y);
}

