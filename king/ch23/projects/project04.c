/*
 * Project 4 from Chapter 23 of King: Write a program that prompts the user to
 * enter a series of words separated by single spaces, then prints the words in
 * reverse order. Read the input as a string, and then use strtok to break it
 * into words.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000
#define MAXWORDS 500

int main(void)
{
	char line[MAXLINE];
	char *words[MAXWORDS];
	char *p;
	int n = 0;

	printf("Enter words separated by a single space: ");
	if (fgets(line, sizeof(line), stdin) == NULL) {
		fprintf(stderr, "Read error encountered\n");
		exit(EXIT_FAILURE);
	}
	line[strcspn(line, "\n")] = '\0';  /* replace newline with null terminator */

	p = strtok(line, " ");
	while (p != NULL && n < MAXWORDS) {
		words[n++] = p;
		p = strtok(NULL, " ");
	}
	for (n--; n >= 0; n--) {
		printf("%s%s", words[n], n ? " " : "\n");
	}

	return 0;
}
