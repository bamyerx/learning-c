/*
 * Exercise 7 from Chapter 19 of King: Modify stackADT2.c so that a stack 
 * automatically doubles in size when it becomes full. Have the push function
 * dynamically allocate a new array that's twice as large as the old one and
 * then copy the stack contents from the old array to the new one. be sure to
 * have push deallocate the old array once the data has been copied.
 */

#include <stdio.h>
#include <stdlib.h>
#include "stackADT2.h"

struct stack_type {
	Item *contents;
	int top;
	int size;
};

static void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Stack create(int size)
{
	Stack s = malloc(sizeof(struct stack_type));
	if (s == NULL)
		terminate("Error in create: stack could not be created.");
	s->contents = malloc(size * sizeof(Item));
	if (s->contents == NULL) {
		free(s);
		terminate("Error in create: stack could not be created.");
	}
	s->top = 0;
	s->size = size;
	return s;
}

void destroy(Stack s)
{
	free(s->contents);
	free(s);
}

void make_empty(Stack s)
{
	s->top = 0;
}

bool is_empty(Stack s)
{
	return s->top == 0;
}

bool is_full(Stack s)
{
	return false;
}

void push(Stack s, Item i)
{
	Item *new_contents;
	int j;

	if (s->top == s->size) {
		new_contents = malloc(2 * s->size * sizeof(Item));
		if (new_contents == NULL)
			terminate("Error in push: stack is full.");
		for (j = 0; j < s->top; j++)
			new_contents[j] = s->contents[j];
		free(s->contents);
		s->contents = new_contents;
		s->size *= 2;
	}

	s->contents[s->top++] = i;
}

int pop(Stack s)
{
	if (is_empty(s))
		terminate("Error in pop: stack is empty.");
	return s->contents[--s->top];
}
