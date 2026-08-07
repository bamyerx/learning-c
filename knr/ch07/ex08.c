/*
 * Exercise 7-8 from K&R: Write a program to print a set of files, starting each
 * new one on a new page, with a title and a running page count for each file.
 */

#include <stdio.h>
#include <stdlib.h>

#define LINES_PER_PAGE 60
#define MAXLINE 1000

void paginate(FILE *, char *);

int main(int argc, char *argv[])
{
	FILE *fp;
	int status = 0;

	if (argc < 2) {
		fprintf(stderr, "Usage: print file [file2 ...]\n");
		exit(2);
	}
	while (--argc > 0) {
		if ((fp = fopen(*++argv, "r")) == NULL) {
			fprintf(stderr, "print: can't open %s\n", *argv);
			status = 1;
		} else {
			paginate(fp, *argv);
			if (ferror(fp))
				status = 1;
			fclose(fp);
		}
	}
	return status;
}

void paginate(FILE *fp, char *filename)
{
	char line[MAXLINE];
	int nlines = 0;
	int npages = 1;

	printf("%s: page 1\n\n", filename);
	while (fgets(line, sizeof(line), fp) != NULL) {
		if (nlines == LINES_PER_PAGE) {
			npages++;
			nlines = 0;
			printf("%s: page %d\n\n", filename, npages);
		}
		printf("%s", line);
		nlines++;
	}
	for (; nlines < LINES_PER_PAGE; nlines++)
		putchar('\n');
}
