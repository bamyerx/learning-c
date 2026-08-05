/*
 * Project 5 from Chapter 17 of King: Write a program that sorts a series of
 * words entered by the user:
 *
 *     Enter word: foo
 *     Enter word: bar
 *     Enter word: baz
 *     Enter word: quux
 *     Enter word:
 *
 *     In sorted order: bar baz foo quux
 *
 * Assume that each word is no more than 20 characters long. Stop reading when
 * the user enters an empty word. Store each word in a dynamically allocated
 * string, using an array of pointers to keep track of the strings as in the
 * remind2.c program. After all words have been read, sort the array (using
 * any sorting technique) and then use a loop to print the words in sorted
 * order.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 20
#define MAXWORDS 40

int read_line(char [], int);
int compare_strings(const void *, const void *);

int main(void)
{
	char *words[MAXWORDS], word[MAXLEN+1];
	int nwords = 0, word_len, i;

	for (;;) {
		if (nwords == MAXWORDS) {
			printf("Maximum number of words reached\n");
			break;
		}
		printf("Enter word: ");
		word_len = read_line(word, MAXLEN);
		if (word_len == 0)
			break;
		words[nwords] = malloc(word_len + 1);
		if (words[nwords] == NULL) {
			printf("Error: memory allocation failed\n");
			exit(EXIT_FAILURE);
		}
		strcpy(words[nwords], word);
		nwords++;
	}

	qsort(words, nwords, sizeof(char *), compare_strings);
	printf("In sorted order:");
	for (i = 0; i < nwords; i++) {
		printf(" %s", words[i]);
		free(words[i]);
	}
	printf("\n");
}

int read_line(char str[], int n)
{
	int ch, i = 0;

	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}

int compare_strings(const void *p, const void *q)
{
	return strcmp(*(char **)p, *(char **)q);
}
