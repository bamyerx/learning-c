/*
 * Exercise 1 from Chapter 19 of King: A queue is similar to a stack, except
 * that items are added at one end but removed from the other in a FIFO (first-
 * in, first-out) fashion. Operations on a queue might include:
 *
 *     Inserting an item at the end of the queue
 *     Removing an item from the beginning of the queue
 *     Returning the first item in the queue (without changing the queue)
 *     Returning the last item in the queue (without changing the queue)
 *     Testing whether the queue is empty
 * 
 * Write an interfact for a queue module in the form of a header file named
 * queue.h.
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

/* make_empty: empty the contents of the queue */
void make_empty(void);

/* is_empty: test if the queue is empty */
bool is_empty(void);

/* is_full: test if the queue is full */
bool is_full(void);

/* enqueue: insert an item at the end of the queue */
void enqeue(int);

/* dequeue: remove an item from the beginning of the queue */
int dequeue(void);

/* front: return the first item in the queue without removing */
int front(void);

/* back: return the last item in the queue without removing */
int back(void);

#endif
