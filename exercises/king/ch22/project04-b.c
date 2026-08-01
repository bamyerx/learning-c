/*
 * Project 4(b) from Chapter 22 of King: Write a program that counts the number
 * of words in a text file. (A "word" is any sequence of non-white-space char-
 * acters.)
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int c, count;
	bool in_space;

	if (argc != 2) {
		fprintf(stderr, "Error: file name required\n");
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Error: can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	count = 0;
	while ((c = getc(fp)) != EOF)
		if (isspace(c))
			in_space = true;
		else if (in_space) {
			in_space = false;
			count++;
		}
	printf("Number of words: %d\n", count);

	fclose(fp);
	return 0;
}
