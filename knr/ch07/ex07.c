/*
 * Exercise 7-7 from K&R: Modify the pattern finding program of Chapter 5 to
 * take its input from a set of named files or, if no files are named as argu-
 * ments, from the standard input. Should the file name be printed when a match-
 * ing line is found?
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

void find(FILE *, char *, char*);

/* find: print lines that match pattern from 1st arg from stdin or from files
 *       Returns 0 if successful (regardless of matches found), 1 if the program
 *       encounters an I/O error, and 2 if invoked incorrectly */
int main(int argc, char *argv[])
{
	FILE *fp;
	char *pattern;
	int multifile = 0;
	int status = 0;

	if (argc < 2) {
		fprintf(stderr, "Usage: find pattern [file ...]\n");
		exit(2);
	}
	pattern = *++argv;
	if (argc == 2)
		find(stdin, pattern, NULL);
	else {
		if (argc > 3)
			multifile = 1;
		while (--argc > 1) {
			if ((fp = fopen(*++argv, "r")) == NULL) {
				fprintf(stderr, "find: can't open %s\n", *argv);
				status = 1;
			} else {
				find(fp, pattern, multifile ? *argv : NULL);
				if (ferror(fp))
					status = 1;
				fclose(fp);
			}
		}
	}
	return status;
}

/* find: print lines that match pattern from stream */
void find(FILE *fp, char *pattern, char *filename)
{
	char line[MAXLINE];

	while (fgets(line, sizeof(line), fp) != NULL)
		if (strstr(line, pattern) != NULL) {
			if (filename != NULL)
				printf("%s:", filename);
			printf("%s", line);
		}
}
