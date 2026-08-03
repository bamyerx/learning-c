/*
 * Exercise 3(a) from Chapter 19 of King: Write an array-based implementation of
 * the queue module described in exercise 1. Use three integers to keep track of
 * the queue's status, with one integer storing the position of the first empty
 * slot in the array (used when an item is inserted), the second storing the
 * position of the next item to be removed, and the third storing the number of
 * itmes in the queue. An insertion or removal that would cause either of the
 * first two integers to be incremented past the end of the array should instead
 * reset the variable to zero, thus causing it to "wrap around" to the beginning
 * of the array.
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define QUEUE_SIZE 100

static int contents[QUEUE_SIZE];
static int next, head, total;

static void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

void make_empty(void)
{
	next = head = total = 0;
}

bool is_empty(void)
{
	return total == 0;
}

bool is_full(void)
{
	return total == QUEUE_SIZE;
}

void enqueue(int n)
{
	if (is_full())
		terminate("Error in enqueue: queue is full");

	contents[next++] = n;
	if (next == QUEUE_SIZE)
		next = 0;
	total++;
}

int dequeue(void)
{
	int n;
	if (is_empty())
		terminate("Error in dequeue: queue is empty");

	n = contents[head++];
	if (head == QUEUE_SIZE)
		head = 0;
	total--;
	return n;
}

int front(void)
{
	if (is_empty())
		terminate("Error in front: queue is empty");
	return contents[head];
}

int back(void)
{
	if (is_empty())
		terminate("Error in back: queue is empty");
	
	return (next == 0) ? contents[QUEUE_SIZE-1] : contents[next-1];
}
