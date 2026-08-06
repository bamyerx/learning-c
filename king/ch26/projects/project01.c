/*
 * Project 1 from Chapter 26 of King: Write a program that calls the rand func-
 * tion 1000 times, printing the low-order bit of each value it returns (0 if
 * the return value is even, 1 if it's odd). Do you see any patterns?
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

int main(void)
{
	int n = N;

	while (n-- > 0) {
		printf("%d", rand() & 1);
		if (n % 100 == 0)
			printf("\n");
	}

	return 0;
}
