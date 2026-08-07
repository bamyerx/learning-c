/*
 * Exercise 7-1 from K&R: Write a program that converts upper case to lower or
 * lower case to upper, depending on the name it is invoked with, as found in
 * argv[0].
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int c;
	char *name = strrchr(argv[0], '/');

	name = name ? name + 1 : argv[0];
	if (strcmp(name, "lower") == 0)
		while ((c = getchar()) != EOF)
			putchar(tolower((unsigned char) c));
	else if (strcmp(name, "upper") == 0)
		while ((c = getchar()) != EOF)
			putchar(toupper((unsigned char) c));
	else {
		fprintf(stderr, "Usage: invoke as 'lower' or 'upper'\n");
		return 1;
	}

	return 0;
}
