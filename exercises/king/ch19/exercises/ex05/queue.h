/*
 * Exercise 5 from Chapter 19 of King: Modify the queue.h header of Exercise 1
 * so that it defines a Queue type, where Queue is a structure containing a
 * fixed-length array. Modify the functions in queue.h to take a Queue *
 * parameter.
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define QUEUE_SIZE;

typedef struct {
	int head;
	int next;
	int tail;
	int contents[QUEUE_SIZE];
} Queue;

/* enqueue: insert an item at the end of the queue */
void enqeue(Queue, int);

/* dequeue: remove an item from the beginning of the queue */
int dequeue(Queue *);

/* front: return the first item in the queue without removing */
int front(Queue *);

/* back: return the last item in the queue without removing */
int back(Queue *);

/* is_empty: test if the queue is empty */
bool is_empty(Queue *);

/* make_empty: empty the contents of the queue */
void make_empty(Queue *);

#endif
