/*
 * Exercise 11 from Chapter 17 of King: Write the following function:
 *
 *     int count_occurrences(struct node *list, int n);
 *
 * The list parameter points to a linked list; the function should return the
 * number of times that n appears in this list. Assume that the node structure
 * is the one defined in Section 17.5.
 */

#include <stdlib.h>

struct node {
	struct node *next;
	int value;
};

int count_occurrences(struct node *list, int n)
{
	int count;

	for (count = 0; list != NULL; list = list->next)
		if (list->value == n)
			count++;
	return count;
}
