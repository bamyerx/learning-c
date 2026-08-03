/*
 * Exercise 1 from Chapter 17 of King: Write a function named my_malloc that
 * serves as a "wrapper" for malloc. When we call my_malloc and ask it to
 * allocate n bytes, it in turn calls malloc, tests to make sure that malloc
 * doesn't return a null pointer, and then returns the pointer from malloc.
 * Have my_malloc print an error message and terminate the program if malloc
 * returns a null pointer.
 */

#include <stdio.h>
#include <stdlib.h>

void *my_malloc(size_t size)
{
	void *p = malloc(size);

	if (p == NULL) {
		printf("Error: malloc returned a null pointer\n");
		exit(EXIT_FAILURE);
	}
	return p;
}
