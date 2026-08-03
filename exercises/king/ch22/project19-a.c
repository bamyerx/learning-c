/*
 * Project 19(a) from Chapter 22 of King: Write a program that converts a
 * Windows text file to a UNIX text file. Have the program obtain the names of
 * both files from the command line.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *src, *dst;
	int c;

	if (argc != 3) {
		fprintf(stderr, "Usage: win2unix windows_file unix_file\n");
		exit(EXIT_FAILURE);
	}
	if ((src = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Error: can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((dst = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "Error, can't open %s\n", argv[2]);
		fclose(src);
		exit(EXIT_FAILURE);
	}

	while ((c = getc(src)) != EOF) {
		if (c != '\x0d' && c != '\x1a')  /* skip CR and Ctrl-Z */
			fputc(c, dst);
	}

	fclose(src);
	fclose(dst);
	return 0;
}
