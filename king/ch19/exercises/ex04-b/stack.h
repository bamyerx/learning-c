#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define STACK_SIZE 100

struct node {
	struct node *next;
	int data;
};

typedef struct node *Stack;

void make_empty(Stack *s);
bool is_empty(const Stack *s);
bool is_full(const Stack *s);
void push(Stack *s, int i);
int pop(Stack *s);

#endif
