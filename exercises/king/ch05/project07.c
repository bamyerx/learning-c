/*
 * Project 7 of chapter 5 of C Programming by K.N. King.
 *
 * Finds the largest and smallest of four integers entered by the user.
 */

#include <stdio.h>

int main(void)
{
    int n1, n2, n3, n4, max1, min1, max2, min2;

    printf("Enter four integers: ");
    scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

    if (n1 >= n2) {
        max1 = n1;
        min1 = n2;
    } else {
        max1 = n2;
        min1 = n1;
    }
    if (n3 >= n4) {
        max2 = n3;
        min2 = n4;
    } else {
        max2 = n4;
        min2 = n3;
    }
    printf("Largest: ");
    if (max1 >= max2) {
        printf("%d\n", max1);
    } else {
        printf("%d\n", max2);
    }
    printf("Smallest: ");
    if (min1 <= min2) {
        printf("%d\n", min1);
    } else {
        printf("%d\n", min2);
    }

    return 0;
}
