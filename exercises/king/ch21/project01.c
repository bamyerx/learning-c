/*
 * Project 1 from Chapter 21 of King: Write a program that declares the s
 * structure (see Section 21.4) and prints the sizes and offsets of the a, b,
 * and c memebers. (Use sizeof to find sizes; use offsetof to find offsets.)
 * Have the program print the size of the entire structure as well. From this
 * information, determine whether or not the structure has any holes. If it
 * does, describe the location and size of each.
 */

/*
 * The program shows that the sizes of a, b, and c are 1, 8, and 4 bytes with
 * offsets of 0, 4, and 12 bytes respectively. This indicates that there is a
 * 3-byte hole following a in s.
 */

#include <stddef.h>
#include <stdio.h>

struct s {
	char a;
	int b[2];
	float c;
};

int main(void)
{
	struct s s;

	printf("Size of a: %ld\n", sizeof(s.a));
	printf("Size of b: %ld\n", sizeof(s.b));
	printf("Size of c: %ld\n", sizeof(s.c));
	
	printf("\n");

	printf("Offset of a: %ld\n", offsetof(struct s, a));
	printf("Offset of b: %ld\n", offsetof(struct s, b));
	printf("Offset of c: %ld\n", offsetof(struct s, c));

	printf("\n");

	printf("Size of s: %ld\n", sizeof(s));
}
