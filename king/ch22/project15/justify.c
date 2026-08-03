/*
 * Project 15 from Chapter 22 of King: Modify the justify program of Section
 * 15.3 so that it reads from one text file and writes to another. Have the
 * program obtain the names of both files from the command line.
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(int argc, char *argv[])
{
	FILE *src, *dst;
	char word[MAX_WORD_LEN+2];
	int word_len;

	if (argc != 3) {
		fprintf(stderr, "Usage: justify source_file destination_file\n");
		exit(EXIT_FAILURE);
	}
	if ((src = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Error: can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((dst = fopen(argv[2], "w")) == NULL) {
		fprintf(stderr, "Error: can't open %s\n", argv[2]);
		fclose(src);
		exit(EXIT_FAILURE);
	}

	clear_line();
	for (;;) {
		word_len = read_word(src, word, MAX_WORD_LEN+1); 
		if (word_len == 0) {
			flush_line(dst);
			return 0;
		}
		if (word_len > MAX_WORD_LEN)
			word[MAX_WORD_LEN] = '*';
		if (word_len + 1 > space_remaining()) {
			write_line(dst);
			clear_line();
		}
		add_word(word);
	}
}
