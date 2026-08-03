/*
 * Exercise 8 from Chapter 17 of King: Modify stack.c so that a stack is now
 * stored as a linked list. Replace the contents and top variables by a single
 * variable that points to the first node in the list (the "top" of the stack).
 * Write the functions in stack.c so that they use this pointer. Remove the
 * is_full function, instead having push return either true (if memory was
 * available to create a node) or false (if not).
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void make_empty(void);
int is_empty(void);
bool push(int i);
int pop(void);

struct node {
	int value;
	struct node *next;
};

struct node *top = NULL;

void make_empty(void)
{
	struct node *temp;

	while (top != NULL) {
		temp = top;
		top = top->next;
		free(temp);
	}
}

int is_empty(void)
{
	return top == NULL;
}

bool push(int i)
{
	struct node *new_node;

	new_node = malloc(sizeof(struct node));
	if (new_node == NULL)
		return false;
	new_node->value = i;
	new_node->next = top;
	top = new_node;

	return true;
}

int pop(void)
{
	struct node *temp;
	int val;

	if (is_empty()) {
		printf("Stack underflow\n");
		exit(EXIT_FAILURE);
	}
	val = top->value;
	temp = top;
	top = top->next;
	free(temp);

	return val;
}
