/*
 * Exercise 12 from Chapter 17 of King: Write the following function:
 *
 *     struct node *find_last(struct node *list, int n);
 *
 * The list parameter points to a linked list. The function should return a
 * pointer to the last node that contains n; it should return NULL if n doesn't
 * appear in the list. Assume that the node structure is the one defined in
 * Section 17.5.
 */

#include <stdlib.h>

struct node {
	struct node *next;
	int value;
};

struct node *find_last(struct node *list, int n)
{
	struct node *last;

	for (last = NULL; list != NULL; list = list->next)
		if (list->value == n)
			last = list;
	return last;
}
