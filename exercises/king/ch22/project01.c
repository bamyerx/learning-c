/*
 * Project 1 from Chapter 22 of King: Extend the canopen.c program of Section
 * 22.2 so that the user may put any number of file names on the command line:
 *
 *     canopen foo bar baz
 *
 * The program should print a separate can be opened or can't be opened message
 * for each file. Have the program terminate with status EXIT_FAILURE if one or
 * more files can't be opened.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	bool failure = false;

	if (argc < 2) {
		printf("usage: canopen filename\n");
		exit(EXIT_FAILURE);
	}
	while (--argc > 0) {
		if ((fp = fopen((++argv)[0], "r")) == NULL) {
			printf("%s can't be opened\n", argv[0]);
			failure = true;
		} else {
			printf("%s can be opened\n", argv[0]);
			fclose(fp);
		}
	}
	if (failure)
		exit(EXIT_FAILURE);

	return 0;
}
