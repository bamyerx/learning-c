/*
 * Exercise 3 from Chapter 24 of King: Modify the stackADT2.c file of Section
 * 19.4 so that it uses assert to test for errors instead of using if state-
 * ments. (Note that the terminate function is no longer necessary and can be
 * removed.)
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stackADT2.h"

struct stack_type {
	Item *contents;
	int top;
	int size;
};

Stack create(int size)
{
	Stack s = malloc(sizeof(struct stack_type));
	assert(s != NULL);
	s->contents = malloc(size * sizeof(Item));
	assert(s->contents != NULL);
	s->top = 0;
	s->size = size;
	return s;
}

void destory(Stack s)
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
	return s-> top == 0;
}

void push(Stack s, Item i)
{
	assert(!is_full(s));
	s->contents[s->top++] = i;
}

Item pop(Stack s)
{
	assert(!is_empty(s));
	return s->contents[--s->top];
}

