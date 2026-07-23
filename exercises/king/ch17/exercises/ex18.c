/*
 * Exercise 18 from Chapter 17 of King: Modify the compare_parts function so
 * that parts are sorted with their numbers in descending order.
 */

#define NAME_LEN 25

struct part {
	int number;
	char name[NAME_LEN+1];
	int on_hand;
	struct part *next;
};

int compare_parts(const void *p, const void *q)
{
	return ((struct part *) q)->number - ((struct part *) p)->number;
}
