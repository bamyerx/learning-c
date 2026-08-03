/*
 * Project 16 from Chapter 22 of King: Modify the fcopy.c program of Section
 * 22.4 so that it uses fread and fwrite to copy the file in blocks of 512
 * bytes.
 */

#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
	FILE *source_fp, *dest_fp;
	char block[BLOCK_SIZE];
	int bytes_read;

	if (argc != 3) {
		fprintf(stderr, "usage: fcopy source dest\n");
		exit(EXIT_FAILURE);
	}

	if ((source_fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((dest_fp = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "Can't open %s\n", argv[2]);
		fclose(source_fp);
		exit(EXIT_FAILURE);
	}

	while ((bytes_read = fread(block, 1, sizeof(block), source_fp)) != 0)
		if (fwrite(block, 1, bytes_read, dest_fp) != bytes_read) {
			fprintf(stderr, "Write error occurred\n");
			exit(EXIT_FAILURE);
		}

	fclose(source_fp);
	fclose(dest_fp);
	return 0;
}
