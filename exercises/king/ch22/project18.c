/*
 * Project 18 from Chapter 22 of King: Write a program that reads integers from
 * a text file whose name is given as a command-line argument. Each line of the
 * file may contain any number of integers (including none) separated by one or
 * more spaces. Have the program display the largest number in the file, the
 * smallest number, and the median. If the file contains an even number of inte-
 * gers, there will be two numbers in the middle; the program should display
 * their average (rounded down). You may assume that the file contains no more
 * than 10,000 integers.
 */

#include <stdio.h>
#include <stdlib.h>

#define NMAX 10000
#define AVG(x,y) ((int) (((long) (x) + (long) (y)) / 2))

int main(int argc, char *argv[])
{
	FILE *fp;
	int ints[NMAX], n;
	int cmpint(const void *, const void *);

	if (argc != 2) {
		fprintf(stderr, "Error: file name is required\n");
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Error: can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	for (n = 0; n < NMAX && fscanf(fp, "%d ", ints + n) == 1; n++)
		;
	if (n == 0) {
		fprintf(stderr, "Error: no integers found\n");
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	qsort(ints, n, sizeof(int), cmpint);
	printf("Minimum: %d, Maximum: %d, Median: %d\n", ints[0], ints[n-1], 
			(n % 2 == 0) ? AVG(ints[n/2-1], ints[n/2]) : ints[n/2]);

	fclose(fp);
	return 0;
}

int cmpint(const void *a, const void *b)
{
	int n1 = *(const int *) a;
	int n2 = *(const int *) b;

	return (n1 > n2) - (n1 < n2);
}
