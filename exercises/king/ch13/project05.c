/*
 * Project 5 from Chapter 13 of King: Write a program named sum.c that adds up
 * its command-line arguments, which are assumed to be integers. Running the
 * program by typing
 *
 *      sum 8 24 62
 *
 * should product the following output:
 *
 *      Total: 94
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, sum = 0;

    for (i = 1; i < argc; i++)
        sum += atoi(argv[i]);
    printf("Total: %d\n", sum);

    return 0;
}
