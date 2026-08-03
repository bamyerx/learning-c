/*
 * Project 14 from Chapter 22 of King: Modify Programming Project 15 from
 * Chapter 8 so that the program prompts the user to enter the name of a file
 * containing the message to be encrypted:
 *
 *     Enter name of file to be encrypted: message.txt
 *     Enter shift amount (1-25): 3
 *
 * The program then writes the encrypted message to a file with the same name
 * but with an added extension of .enc. In this example, the original file name
 * is message.txt, so the encrypted message will be stored in a file named
 * message.txt.enc. There's no limit on the size of the file to be encrypted or
 * on the length of each line in the file.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 100

void encrypt(char *, int);

int main(void)
{
	FILE *src, *dst;
	char filename[MAX_FILENAME];
    int c, shift;

    printf("Enter name of file to be encrypted: ");
	scanf("%s", filename);
	if ((src = fopen(filename, "r")) == NULL) {
		fprintf(stderr, "Error: %s can't be opened\n", filename);
		exit(EXIT_FAILURE);
	}
	if ((dst = fopen(strcat(filename, ".enc"), "w")) == NULL) {
		fprintf(stderr, "Error: %s.enc can't be opened\n", filename);
		fclose(src);
		exit(EXIT_FAILURE);
	}

	do {
		printf("Enter shift amount (1-25): ");
		scanf("%d", &shift);
		if (shift < 1 || shift > 25)
			printf("Invalid shift amount\n");
	} while (shift < 1 || shift > 25);
	while ((c = getc(src)) != EOF) {
		if (c >= 'A' && c <= 'Z')
			putc((c - 'A' + shift) % 26 + 'A', dst);
		else if (c >= 'a' && c <= 'z')
			putc((c - 'a' + shift) % 26 + 'a', dst);
		else
			putc(c, dst);
	}

	fclose(src);
	fclose(dst);
    return 0;
}
