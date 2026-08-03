/*
 * Project 7(b) from Chapter 22 of King: Write a program named uncompress_file
 * that reverses the compression performed by the compress_file program. The
 * uncompress_file program will have the form
 *
 *     uncompress_file compressed-file
 *
 * compressed-file should have the extension .rle. For example, the command
 *
 *     uncompress_file foo.txt.rle
 *
 * will cause uncompress_file to open the file foo.txt.rle and write an uncom-
 * pressed version of its contents to foo.txt. uncompress_file should display an
 * error message if its command-line argument doesn't end with the .rle exten-
 * sion.
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define EXT ".rle"

int main(int argc, char *argv[])
{
	FILE *src, *dst;
	int c, rep, flen, elen;

	if (argc != 2) {
		fprintf(stderr, "Usage: uncompress_file filename\n");
		exit(EXIT_FAILURE);
	}
	flen = strlen(argv[1]);
	elen = strlen(EXT);
	if (elen > flen || strcmp(EXT, argv[1] + flen - elen) != 0) {
		fprintf(stderr, "Error: filename must end in .rle\n");
		exit(EXIT_FAILURE);
	}
	if ((src = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Error: can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	argv[1][flen - elen] = '\0';
	if ((dst = fopen(argv[1], "wb")) == NULL) {
		fprintf(stderr, "Error: can't open %s\n", argv[1]);
		fclose(src);
		exit(EXIT_FAILURE);
	}

	while ((c = getc(src)) != EOF) {
		rep = c;
		c = getc(src);
		while (c != EOF && rep--)
			putc(c, dst);
	}

	fclose(src);
	fclose(dst);
	return 0;
}
