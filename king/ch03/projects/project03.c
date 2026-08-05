/*
 * Project 3 from Chapter 3 of King: Write a program that breaks down an ISBN
 * entered by the user:
 *
 *     Enter ISBN: 978-0-393-97950-3
 *     GS1 Prefix: 978
 *     Group identifier: 0
 *     Publisher code: 393
 *     Item number: 97950
 *     Check digit: 3
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
    printf("Check digit: %d\n", check_digit);

    return 0;
}
