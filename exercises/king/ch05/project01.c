/*
 * Project 1 of chapter 5 of C Programming by K.N. King.
 *
 * Calculates how many digits a number contains.
 *
 * Note: It is assumed that the number has no more than four digits.
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
