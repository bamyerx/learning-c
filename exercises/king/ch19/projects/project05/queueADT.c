#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

#define QUEUE_SIZE 100

struct queue_type {
	int contents[QUEUE_SIZE];
	int next, head, total;
};

static void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Queue create(void)
{
	Queue q = malloc(sizeof(struct queue_type));
	if (q == NULL)
		terminate("Error in create: queue could not be created");
	q->next = q->head = q->total = 0;
	return q;
}

void destroy(Queue q)
{
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
	return q->total == QUEUE_SIZE;
}

void enqueue(Queue q, int n)
{
	if (is_full(q))
		terminate("Error in enqueue: queue is full");

	q->contents[q->next++] = n;
	if (q->next == QUEUE_SIZE)
		q->next = 0;
	q->total++;
}

int dequeue(Queue q)
{
	int n;
	if (is_empty(q))
		terminate("Error in dequeue: queue is empty");

	n = q->contents[q->head++];
	if (q->head == QUEUE_SIZE)
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
	
	return (q->next == 0) ? q->contents[QUEUE_SIZE-1] : q->contents[q->next-1];
}
