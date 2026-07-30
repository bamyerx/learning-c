#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct queue_type {
	int *contents;
	int next, head, total, size;
};

static void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Queue create(int size)
{
	Queue q = malloc(sizeof(struct queue_type));
	if (q == NULL)
		terminate("Error in create: queue could not be created");
	q->contents = malloc(size * sizeof(int));
	if (q->contents == NULL) {
		free(q);
		terminate("Error in create: queue could not be created");
	}
	q->size = size;
	q->next = q->head = q->total = 0;
	return q;
}

void destroy(Queue q)
{
	free(q->contents);
	free(q);
}

void make_empty(Queue q)
{
	q->next = q->head = q->total = 0;
}

bool is_empty(Queue q)
{
	return q->total == 0;
}

bool is_full(Queue q)
{
	return q->total == q->size;
}

void enqueue(Queue q, int n)
{
	if (is_full(q))
		terminate("Error in enqueue: queue is full");

	q->contents[q->next++] = n;
	if (q->next == q->size)
		q->next = 0;
	q->total++;
}

int dequeue(Queue q)
{
	int n;
	if (is_empty(q))
		terminate("Error in dequeue: queue is empty");

	n = q->contents[q->head++];
	if (q->head == q->size)
		q->head = 0;
	q->total--;
	return n;
}

int front(Queue q)
{
	if (is_empty(q))
		terminate("Error in front: queue is empty");
	return q->contents[q->head];
}

int back(Queue q)
{
	if (is_empty(q))
		terminate("Error in back: queue is empty");
	
	return (q->next == 0) ? q->contents[q->size-1] : q->contents[q->next-1];
}
