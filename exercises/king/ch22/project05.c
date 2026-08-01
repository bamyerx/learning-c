/*
 * Project 5 from Chapter 22 of King: The xor.c program of Section 20.1 refuses
 * to encrypt bytes that--in original or encrypted form--are control characters.
 * We can now remove this restriction. Modify the program so that the names of
 * the input and output files are command-line arguments. Open both files in
 * binary mode, and remove the test that checks whether the original and 
 * encrypted characters are printing characters.
 */

#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

int main(int argc, char *argv[])
{
	FILE *input, *output;
	int orig_char, new_char;

	if (argc != 3) {
		fprintf(stderr, "Usage: xor input_file output_file\n");
		exit(EXIT_FAILURE);
	}
	if ((input = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Error: can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((output = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "Error: can't open %s\n", argv[2]);
		fclose(input);
		exit(EXIT_FAILURE);
	}

	while ((orig_char = getc(input)) != EOF) {
		new_char = orig_char ^ KEY;
		putc(new_char, output);
	}

	fclose(input);
	fclose(output);
	return 0;
}
