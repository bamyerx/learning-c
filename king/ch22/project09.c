/*
 * Project 9 from Chapter 22 of King: Write a program that merges two files con-
 * taining part records stored by the inventory.c program. Assume that the 
 * records in each file are sorted by part number, and that we want the result-
 * ing file to be sorted as well. If both files have a part with the same
 * number, combine the quantities stored in the records. (As a consistency
 * check, have the program compare the part names and print an error message if
 * they don't match.) Have the program obtain the names of the input files and
 * the merged file from the command line.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
	int number;
	char name[NAME_LEN+1];
	int on_hand;
};

int main(int argc, char *argv[])
{
	FILE *fp;
	struct part inv1[MAX_PARTS], inv2[MAX_PARTS], inv[MAX_PARTS];
	int nparts1, nparts2, i, j, k;

	if (argc != 4) {
		fprintf(stderr, "Usage: mergeinvs input1 input2 output\n");
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Error: can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	nparts1 = fread(inv1, sizeof(inv1[0]), sizeof(inv1) / sizeof(inv1[0]), fp);
	fclose(fp);

	if ((fp = fopen(argv[2], "rb")) == NULL) {
		fprintf(stderr, "Error: can't open %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	nparts2 = fread(inv2, sizeof(inv2[0]), sizeof(inv2) / sizeof(inv2[0]), fp);
	fclose(fp);

	if (nparts1 + nparts2 > MAX_PARTS) {
		fprintf(stderr, "Error: too many parts to merge\n");
		exit(EXIT_FAILURE);
	}
	for (i = j = k = 0; j < nparts1 && k < nparts2; i++) {
		if (inv1[j].number < inv2[k].number)
			inv[i] = inv1[j++];
		else if (inv1[j].number > inv2[k].number)
			inv[i] = inv2[k++];
		else {
			if (strcmp(inv1[j].name, inv2[k].name) != 0)
				fprintf(stderr, "Error: part name mismatch for part %d\n", inv1[j].number);
			inv[i] = inv1[j++];
			inv[i].on_hand += inv2[k++].on_hand;
		}
	}
	while (j < nparts1) {
		inv[i++] = inv1[j++];
	}
	while (k < nparts2) {
		inv[i++] = inv2[k++];
	}

	if ((fp = fopen(argv[3], "wb")) == NULL) {
		fprintf(stderr, "Error: can't open %s\n", argv[3]);
		exit(EXIT_FAILURE);
	}
	fwrite(inv, sizeof(inv[0]), i, fp);

	fclose(fp);
	return 0;
}
