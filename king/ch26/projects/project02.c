/*
 * Project 2 from Chapter 26 of King: Write a program that tests the atexit
 * function. The program should have two functions (in addition to main), one of
 * which prints That's all, and the other folks!. Use the atexit function to
 * register both to be called at program termination. Make sure they're called
 * in the proper order, so that we see the message That's all, folks! on the
 * screen.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	void f1(void);
	void f2(void);

	atexit(f2);
	atexit(f1);

	return 0;
}

void f1(void)
{
	printf("That's all, ");
}

void f2(void)
{
	printf("folks!\n");
}
