/*
 * Project 2 from chapter 3 of C Programming by K.N. King.
 *
 * Formats product information entered by the user.
 */

#include <stdio.h>

int main(void)
{
    int item, month, day, year;
    float price;

    printf("Enter item number: ");
    scanf("%d", &item);
    printf("Enter unit price: ");
    scanf("%f", &price);
    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
    printf("%-d\t\t$%7.2f\t%-d/%d/%d\n", item, price, month, day, year);

    return 0;
}
