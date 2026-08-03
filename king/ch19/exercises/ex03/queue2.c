/*
 * Exercise 3(b) from Chapter 19 of King: Write a linked list implementation of
 * the queue module described in Exercise 1. Use two pointers, one pointing to
 * the first node in the list and the other pointing to the last node. When an
 * item is inserted into the queue, add it to the end of the list. When an item
 * is removed from the queue, delete the first node in the list.
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct node {
	struct node *next;
	int data;
};

static struct node *head = NULL;
static struct node *tail = NULL;

static void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

void make_empty(void)
{
	while (!is_empty())
		dequeue();
}

bool is_empty(void)
{
	return head == NULL;
}

bool is_full(void)
{
	return false;
}

void enqueue(int n)
{
	struct node *new_node = malloc(sizeof(struct node));
	if (new_node == NULL)
		terminate("Error in enqueue: queue is full.");

	new_node->data = n;
	new_node->next = NULL;
	if (is_empty())
		head = tail = new_node;
	else {
		tail->next = new_node;
		tail = new_node;
	}
}

int dequeue(void)
{
	struct node *old_head;
	int n;

	if (is_empty())
		terminate("Error in dequeue: queue is empty.");

	old_head = head;
	n = head->data;
	if((head = head->next) == NULL)
		tail = NULL;
	free(old_head);
	return n;
}

int front(void)
{
	if (is_empty())
		terminate("Error in front: queue is empty.");
	
	return head->data;
}

int back(void)
{
	if (is_empty())
		terminate("Error in back: queue is empty.");

	return tail->data;
}
