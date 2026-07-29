/*
 * Exercise 4(b) from Chapter 19 of King: Redo the Stack type, this time using a
 * linked-list representation instead of an array.
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

static void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

void make_empty(Stack *s)
{
	while (!is_empty(s))
		pop(s);
}

bool is_empty(const Stack *s)
{
	return *s == NULL;
}

bool is_full(const Stack *s)
{
	return false;
}

void push(Stack *s, int i)
{
	struct node *new_node;

	if ((new_node = malloc(sizeof(struct node))) == NULL)
		terminate("Error in push: stack is full.");

	new_node->data = i;
	new_node->next = *s;
	*s = new_node;
}

int pop(Stack *s)
{
	struct node *old_top;
	int i;

	if (is_empty(s))
		terminate("Error in pop: stack is empty.");

	old_top = *s;
	i = old_top->data;
	*s = old_top->next;
	free(old_top);
	return i;
}
