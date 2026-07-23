/*
 * Project 4 from Chapter 17 of King: Modify the justify program of Section 15.3
 * by rewriting the line.c file so that it stores the current line in a linked
 * list. Each node in the list will store a single word. The line array will be
 * replaced by a variable that points to the node containing the first word.
 * This variable will store a null pointer whenever the line is empty.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

struct node {
	struct node *next;
	char *word;
};

struct node *line = NULL;
struct node *last = NULL;
int line_len = 0;
int num_words = 0;

void clear_line(void)
{
	struct node *temp;

	while (line != NULL) {
		temp = line;
		line = line->next;
		free(temp->word);
		free(temp);
	}
	last = NULL;
	line_len = 0;
	num_words = 0;
}

void add_word(const char *word)
{
	int word_len;
	struct node *new_node;

	word_len = strlen(word);
	new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("Error: malloc failed in add_word\n");
		exit(EXIT_FAILURE);
	}
	new_node->word = malloc(word_len + 1);
	if (new_node->word == NULL) {
		printf("Error: malloc failed in add_word\n");
		exit(EXIT_FAILURE);
	}
	strcpy(new_node->word, word);
	new_node->next = NULL;
	if (num_words == 0)
		line = new_node;
	if (num_words > 0)
		last->next = new_node;
	last = new_node;
	line_len += word_len;
	num_words++;
}

int space_remaining(void)
{
	return MAX_LINE_LEN - (line_len + num_words - 1);
}

void write_line(void)
{
	int spaces, spaces_to_insert, words_left, i;
	struct node *current;

	spaces = MAX_LINE_LEN - line_len;
	words_left = num_words;
	for (current = line; current != NULL; current = current->next) {
		printf("%s", current->word);
		if (words_left > 1) {
			spaces_to_insert = spaces / (words_left - 1);
			for (i = 0; i < spaces_to_insert; i++)
				putchar(' ');
			spaces -= spaces_to_insert;
		}
		words_left--;
	}
	putchar('\n');
}

void flush_line(void)
{
	struct node *current;

	for (current = line; current != NULL; current = current->next) {
		printf("%s", current->word);
		if (current->next != NULL)
			putchar(' ');
	}
	putchar('\n');
}
