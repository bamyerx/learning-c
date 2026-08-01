/*
 * Project 2 from Chapter 22 of King: Write a program that converts all letters
 * in a file to upper case. (Characters other than letters shouldn't be changed.)
 * The program should obtain the file name from the command line and write its
 * output to stdout.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int c;

	if (argc != 2) {
		fprintf(stderr, "Error: must have exactly one filename argument\n");
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Error: can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	while ((c = getc(fp)) != EOF)
		putc(toupper(c), stdout);
	
	fclose(fp);
	return 0;
}
