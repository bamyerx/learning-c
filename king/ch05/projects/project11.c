/*
 * Project 11 from Chapter 5 of King: Write a program that asks the user for a
 * two-digit number, then prints the English word for the number:
 *
 *     Enter a two-digit number: 45
 *     You entered the number forty-five.
 */

#include <stdio.h>

int main(void)
{
    int n, d1, d2;

    printf("Enter a two-digit number: ");
    scanf("%d", &n);
    if (n < 10 || n > 99) {
        printf("Please enter a valid number.\n");
        return 0;
    }
    d1 = n / 10;
    d2 = n % 10;

    printf("You entered the number ");
    if (d1 == 1) {
        switch (n) {
            case 10: printf("ten.\n");       break;
            case 11: printf("eleven.\n");    break;
            case 12: printf("twelve.\n");    break;
            case 13: printf("thirteen.\n");  break;
            case 14: printf("fourteen.\n");  break;
            case 15: printf("fifteen.\n");   break;
            case 16: printf("sixteen.\n");   break;
            case 17: printf("seventeen.\n"); break;
            case 18: printf("eighteen.\n");  break;
            case 19: printf("nineteen.\n");  break;
        }
        return 0;
    }
    switch (d1) {
        case 2: printf("twenty");  break;
        case 3: printf("thirty");  break;
        case 4: printf("forty");   break;
        case 5: printf("fifty");   break;
        case 6: printf("sixty");   break;
        case 7: printf("seventy"); break;
        case 8: printf("eighty");  break;
        case 9: printf("ninety");  break;
    }
    switch (d2) {
        case 0: printf(".\n");       break;
        case 1: printf("-one.\n");   break;
        case 2: printf("-two.\n");   break;
        case 3: printf("-three.\n"); break;
        case 4: printf("-four.\n");  break;
        case 5: printf("-five.\n");  break;
        case 6: printf("-six.\n");   break;
        case 7: printf("-seven.\n"); break;
        case 8: printf("-eight.\n"); break;
        case 9: printf("-nine.\n");  break;
    }

    return 0;
}
