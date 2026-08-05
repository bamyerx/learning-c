/*
 * Project 12 from Chapter 22 of King: Modify Programming Project 2 from Chapter
 * 3 so that the program reads a series of items from a file and displays the
 * data in columns. Each line of the file will have the following form:
 *
 *     item,price,mm/dd/yyyy
 *
 * For example, suppose that the file contains the following lines:
 *
 *     583,13.5,10/24/2005
 *     3912,599.99,7/27/2008
 *
 * The output of the program should have the following appearance:
 *
 *     Item				Unit				Purchase
 *						Price				Date
 *     583				$  13.50			10/24/2005
 *     3912				$ 599.99			7/27/2008
 *
 * Have the program obtain the file name from the command line.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100

int main(int argc, char *argv[])
{
	FILE *fp;
	int item, month, day, year;
	float price;
	char line[MAXLINE];

	if (argc != 2) {
		fprintf(stderr, "Error: filename is required\n");
		exit(EXIT_FAILURE);
	}
	
	if ((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Error: can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
	while (fgets(line, MAXLINE, fp) != NULL) {
		sscanf(line, "%d,%f,%d/%d/%d", &item, &price, &month, &day, &year);
		printf("%-d\t\t$%7.2f\t%.2d/%.2d/%.4d\n", item, price, month, day, year);
	}

	fclose(fp);
	return 0;
}
