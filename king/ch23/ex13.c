/*
 * Exercise 13 from Chapter 23 of King: Use strtok to write the following
 * function:
 *
 *     int count_words(char *sentence);
 *
 * count_words returns the number of words in the string sentence, where a
 * "word" is any sequence of non-white-space characters. count_words is allowed
 * to modify the string.
 */

#include <ctype.h>
#include <stdbool.h>
#include <string.h>

int count_words(char *sentence)
{
	int count = 0;

	while (strtok(sentence, " \t") != NULL) {
		count++;
		sentence = NULL;
	}
	return count;
}
