#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

typedef struct queue_type *Queue;

/* create: make and allocate a new queue */
Queue create(int size);

/* destroy: destory and deallocate a queue */
void destroy(Queue);

/* make_empty: empty the contents of the queue */
void make_empty(Queue);

/* is_empty: test if the queue is empty */
bool is_empty(Queue);

/* is_full: test if the queue is full */
bool is_full(Queue);

/* enqueue: insert an item at the end of the queue */
void enqueue(Queue, int);

/* dequeue: remove an item from the beginning of the queue */
int dequeue(Queue);

/* front: return the first item in the queue without removing */
int front(Queue);

/* back: return the last item in the queue without removing */
int back(Queue);

#endif
