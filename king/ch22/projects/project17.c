/*
 * Project 17 from Chapter 22 of King: Write a program that reads a series of
 * phone numbers from a file and displays them in a standard format. Each line
 * of the file will contain a single phone number, but the numbers may be in a
 * variety of formats. You may assume that each line contains 10 digits, possi-
 * bly mixed with other characters (which should be ignored). For example,
 * suppose that the file contains the following lines:
 *
 *     404.817.6900
 *     (215) 686-1776
 *     312-746-6000
 *     877 275 5273
 *     6173434200
 *
 * The output of the program should have the following appearance:
 *
 *     (404) 817-6900
 *     (215) 686-1776
 *     (312) 746-6000
 *     (877) 275-5273
 *     (617) 343-4200
 *
 * Have the program obtain the file name from the command line.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100

int main(int argc, char *argv[])
{
	FILE *fp;
	int c, n;
	char buf[10];

	if (argc != 2) {
		fprintf(stderr, "Error: file name is required\n");
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Error: can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	n = 0;
	while ((c = getc(fp)) != EOF) {
		if (isdigit(c))
			buf[n++] = c;
		if (n == 10) {
			printf("(%c%c%c) %c%c%c-%c%c%c%c\n",
					buf[0], buf[1], buf[2], buf[3], buf[4],
					buf[5], buf[6], buf[7], buf[8], buf[9]);
			n = 0;
		}
    }

	fclose(fp);
	return 0;
}
