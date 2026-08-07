/*
 * Exercise 7-6 from K&R: Write a program to compare two files, printing the 
 * first line where they differ.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;
	char line1[MAXLINE], line2[MAXLINE];
	char *p1, *p2;
	int n = 0;

	if (argc != 3) {
		fprintf(stderr, "Usage: firstdiff file1 file2\n");
		exit(1);
	}
	if ((fp1 = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "firstdiff: can't open %s\n", argv[1]);
		exit(1);
	}
	if ((fp2 = fopen(argv[2], "r")) == NULL) {
		fprintf(stderr, "firstdiff: can't open %s\n", argv[2]);
		exit(1);
	}
	for (;;) {
		p1 = fgets(line1, MAXLINE, fp1);
		p2 = fgets(line2, MAXLINE, fp2);
		n++;
		if (p1 == NULL || p2 == NULL)
			break;
		if (strcmp(line1, line2) != 0) {
			printf("%s:%d: %s", argv[1], n, line1);
			printf("%s:%d: %s", argv[2], n, line2);
			fclose(fp1);
			fclose(fp2);
			return 0;
		}
	}
	if (ferror(fp1) || ferror(fp2)) {
		if (ferror(fp1))
			fprintf(stderr, "firstdiff: read error on %s\n", argv[1]);
		if (ferror(fp2)) 
			fprintf(stderr, "firstdiff: read error on %s\n", argv[2]);
		exit(1);
	} else if (feof(fp1) && feof(fp2)) {
		printf("files are identical\n");
	} else if (feof(fp1)) {
		printf("%s: end of file\n", argv[1]);
		printf("%s:%d: %s", argv[2], n, line2);
	} else {
		printf("%s:%d: %s", argv[1], n, line1);
		printf("%s: end of file\n", argv[2]);
	}

	fclose(fp1);
	fclose(fp2);
	return 0;
}
