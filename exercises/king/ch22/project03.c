/*
 * Project 3 from Chapter 22 of King: Write a program named fcat that
 * "concatenates" any number of files by writing them to standard output, one
 * after the other, with no breaks between files. For example, the following
 * command will display the files f1.c, f2.c, and f3.c on the screen:
 *
 *     fcat f1.c f2.c f3.c
 *
 * fcat should issue an error message if any file can't be opened.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int c;

	if (argc < 2) {
		fprintf(stderr, "Error: at least one filename required\n");
		exit(EXIT_FAILURE);
	}
	while (--argc > 0) {
		if ((fp = fopen((++argv)[0], "r")) == NULL) {
			fprintf(stderr, "Error: can't open %s\n", argv[0]);
			exit(EXIT_FAILURE);
		}
		while ((c = getc(fp)) != EOF) {
			putchar(c);
		}
		fclose(fp);
	}

	return 0;
}
