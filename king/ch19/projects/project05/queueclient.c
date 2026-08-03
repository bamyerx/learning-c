/*
 * Project 5 from Chapter 19 of King: Starting from the queue.h header of
 * Exercise 1, create a file named queueADT.h that defines the following Queue
 * type:
 *
 *     typedef struct queue_type *Queue;
 *
 * queue_type is an incomplete structure type. Create a file named queueADT.c
 * that contains the full definition of queue_type as well as definitions for
 * all the functions in queue.h. Use a fixed-length array to store the items in
 * a queue. Create a file named queueclient.c that creates two queues and
 * performs operations on them.
 */

#include <stdio.h>
#include "queueADT.h"

int main(void)
{
	Queue q1, q2;
	int n;

	q1 = create();
	q2 = create();

	enqueue(q1, 1);
	enqueue(q1, 2);

	n = dequeue(q1);
	printf("Dequeued %d from q1\n", n);
	enqueue(q2, n);
	n = dequeue(q1);
	printf("Dequeued %d from q1\n", n);
	enqueue(q2, n);

	destroy(q1);

	while (!is_empty(q2)) {
		printf("Dequeued %d from q2\n", dequeue(q2));
	}

	enqueue(q2, 3);
	make_empty(q2);
	if (is_empty(q2))
		printf("q2 is empty\n");
	else
		printf("q2 is not empty\n");

	destroy(q2);

	return 0;
}
