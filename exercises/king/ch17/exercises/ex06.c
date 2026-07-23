/*
 * Exercise 6 from Chapter 17 of King: Modify the delete_from_list function so
 * that it uses only one pointer variable instead of two (cur and prev).
 */

#include <stdlib.h>

struct node {
	struct node *next;
	int value;
};

struct node *delete_from_list(struct node *list, int n)
{
	struct node **cur, *temp;

	cur = &list;
	while (*cur != NULL && (*cur)->value != n) {
		*cur = (*cur)->next;
	}
	if (*cur == NULL)
		return list;
	temp = *cur;
	*cur = (*cur)->next;
	free(temp);
	return list;
}
