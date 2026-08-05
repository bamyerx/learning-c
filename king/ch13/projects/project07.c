/*
 * Project 7 from Chapter 13 of King: Modify Programming Project 11 from Chapter
 * 5 so that it uses arrays containing pointers to strings instead of switch
 * statements. For example, instead of using a switch statement to print the
 * word for the first digit, use the digit as an index into an array that 
 * contains the strings "twenty", "thirty", and so forth.
 */

#include <stdio.h>

int main(void)
{
    int n, d1, d2;
    char *ones[] =  {"", "-one", "-two", "-three", "-four",
                     "-five", "-six", "-seven", "-eight", "nine"},
         *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen",
                     "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"},
         *tens[] =  {"", "", "twenty", "thirty", "forty", "fifty",
                     "sixty", "seventy", "eighty", "ninety"};

    printf("Enter a two-digit number: ");
    scanf("%d", &n);
    if (n < 10 || n > 99) {
        printf("Please enter a valid number.\n");
        return 0;
    }
    d1 = n / 10;
    d2 = n % 10;

    printf("You entered the number ");
    if (d1 == 1)
        printf("%s.\n", teens[d2]);
    else 
        printf("%s%s.\n", tens[d1], ones[d2]);

    return 0;
}
