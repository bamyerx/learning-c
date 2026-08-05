/*
 * Project 1 of Chapter 5 of King: Write a program that calculates how many
 * digits a number contains:
 *
 *     Enter a number: 374
 *     The number 374 has 3 digits
 *
 * You may assume that the number has no more than four digits.
 */

#include <stdio.h>

int main(void)
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("The number %d has ", n);
    if (n > 999) {
        printf("4");
    } else if (n > 99) {
        printf("3");
    } else if (n > 9) {
        printf("2");
    } else {
        printf("1");
    }
    printf(" digits\n");

    return 0;
}
