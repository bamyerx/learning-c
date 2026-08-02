/*
 * Project 7(a) from Chapter 22 of King: Write a program named compress_file
 * that uses run-length encoding to compress a file. To run compress_file, we'd
 * use a command of the form
 *
 *     compress_file original-file
 *
 * compress_file will write the compressed version of original-file to
 * original-file.rle.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *src, *dst;
	int c, prev, rep;

	if (argc != 2) {
		fprintf(stderr, "Usage: compress_file filename\n");
		exit(EXIT_FAILURE);
	}
	if ((src = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Error: can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((dst = fopen(strcat(argv[1], ".rle"), "wb")) == NULL) {
		fprintf(stderr, "Error: can't open %s.rle\n", argv[1]);
		fclose(src);
		exit(EXIT_FAILURE);
	}

	for (prev = EOF, rep = 0; (c = getc(src)) != EOF; rep++) {
		if (c != prev && prev != EOF) {
			putc(rep, dst);
			putc(prev, dst);
			prev = c;
			rep = 0;
		}
		prev = c;
	}
	putc(rep, dst);
	putc(prev, dst);

	fclose(src);
	fclose(dst);
	return 0;
}
