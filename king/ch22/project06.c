/*
 * Project 6 from Chapter 22 of King: Write a program that displays the contents
 * of a file as bytes and as characters. Have the user specify the file name on
 * the command line. Here's what the output will look like when the program is
 * used to display the pun.c file of Section 2.1:
 *
 *     Offset              Bytes              Characters
 *     ------  -----------------------------  ----------
 *          0  23 69 6E 63 6C 75 64 65 20 3C  #include <
 *         10  73 74 64 69 6F 2E 68 3E 0D 0A  stdio.h>..
 *         20  0D 0A 69 6E 74 20 6D 61 69 6E  ..int main
 *         30  28 76 6F 69 64 29 0D 0A 7B 0D  (void)..{.
 *         40  0A 20 20 70 72 69 6E 74 66 28  .  printf(
 *         50  22 54 6F 20 43 2C 20 6F 72 20  "To C, or 
 *         60  6E 6F 74 20 74 6F 20 43 3A 20  not to C: 
 *         70  74 68 61 74 20 69 73 20 74 68  that is th
 *         80  65 20 71 75 65 73 74 69 6F 6E  e question
 *         90  2E 5C 6E 22 29 3B 0D 0A 20 20  .\n");..  
 *        100  72 65 74 75 72 6E 20 30 3B 0D  return 0;.
 *        110  0A 7D                          .}
 *
 * Each line shows 10 bytes from the file, as hexadecimal numbers and as charac-
 * ters. The number in the Offset column indicates the position within the file
 * of the first byte on the line. Only printing characters (as determined by the
 * isprint function) are displayed; other characters are shown as periods.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define NBYTES 10

int main(int argc, char *argv[])
{
	FILE *fp;
	int c, offset, i;
	char s[NBYTES+1];

	if (argc != 2) {
		fprintf(stderr, "Error: file name is required\n");
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Error: %s can't be opened\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	printf("Offset              Bytes              Characters\n");
	printf("------  -----------------------------  ----------\n");
	offset = 0;
	while ((c = getc(fp)) != EOF) {
		printf("%6d ", offset);
		for (i = 0; i < NBYTES; i++) {
			if (c != EOF) {
				printf(" %02X", c);
				s[i] = isprint(c) ? c : '.';
				c = getc(fp);
				offset++;
			} else {
				s[i] = ' ';
				printf("   ");
			}
		}
		if (c != EOF)
			ungetc(c, fp);
		s[i] = '\0';
		printf("  %s\n", s);
	}

	fclose(fp);
	return 0;
}
