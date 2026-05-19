/*
 * Project 3 from chapter 3 of C Programming by K.N. King.
 *
 * Breaks down an ISBN-13 entered by the user.
 */

#include <stdio.h>

int main(void)
{
    int prefix, group, publisher, item, check_digit;

    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &prefix, &group, &publisher, &item, &check_digit);

    printf("GS1 Prefix: %.3d\n", prefix);
    printf("Group identifier: %d\n", group);
    printf("Publisher code: %d\n", publisher);
    printf("Item number: %d\n", item);
    printf("Check digit: %.1d\n", check_digit);

    return 0;
}
