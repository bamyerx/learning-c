/*
 * Project 7 from Chapter 23 of King: Write a program that counts the number of
 * sentences in a text file (obtained from standard input). Assume that each
 * sentence ends with a ., ?, or ! followed by a white-space character
 * (including \n).
 */

#include <ctype.h>
#include <stdio.h>

int main(void)
{
	int c, count = 0;

	while ((c = getchar()) != EOF) {
		if (c == '.' || c == '?' || c == '!') {
			c = getchar();
			if (c == EOF || isspace((unsigned char) c))
				count++;
			else
				ungetc(c, stdin);
		}
	}
	printf("Sentence count: %d\n", count);

	return 0;
}
