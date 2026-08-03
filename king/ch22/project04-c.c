/*
 * Project 4(c) from Chapter 22 of King: Write a program that counts the number
 * of lines in a text file.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int c, count;

	if (argc != 2) {
		fprintf(stderr, "Error: file name is required\n");
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Error: can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	count = 0;
	while ((c = getc(fp)) != EOF)
		if (c == '\n')
			count++;
	printf("Number of lines: %d\n", count);

	fclose(fp);
	return 0;
}
