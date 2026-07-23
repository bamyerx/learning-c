/*
 * Exercise 14 from Chapter 17 of King: Modify the delete_from_list function
 * (Section 17.5) so that its first parameter has type struct node ** (a pointer
 * to a pointer to the first node in a list) and its return type is void.
 * delete_from_list must modify its first argument to point to the list after
 * the desired node has been deleted.
 */

#include <stdlib.h>

struct node {
	struct node *next;
	int value;
};

void delete_from_list(struct node **list, int n)
{
	struct node *cur, *prev;

	for (cur = *list, prev = NULL;
		 cur != NULL && cur->value != n;
		 prev = cur, cur = cur->next)
		;
	if (cur == NULL)
		return;
	if (prev == NULL)
		*list = (*list)->next;
	else 
		prev->next = cur->next;
	free(cur);
}
