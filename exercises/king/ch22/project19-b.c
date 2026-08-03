/*
 * Project 19(b) from Chapter 22 of King: Write a program that converts a UNIX
 * text file to a Windows text file. Have the program obtain the names of both 
 * files from the command line.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *src, *dst;
	int c;

	if (argc != 3) {
		fprintf(stderr, "Usage: unix2win unix_file windows_file\n");
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
		if (c == '\x0a')
			fputc('\x0d', dst);
		fputc(c, dst);
	}
	fputc('\x1a', dst);

	fclose(src);
	fclose(dst);
	return 0;
}
