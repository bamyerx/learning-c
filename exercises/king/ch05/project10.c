/*
 * Project 10 from chapter 5 of C Programming by K.N. King.
 *
 * Converts a numerical grade into a letter grade.
 */

#include <stdio.h>

int main(void)
{
    int grade;

    printf("Enter numerical grade: ");
    scanf("%d", &grade);

    if (grade > 100 || grade < 0) {
        printf("Please enter a valid grade.\n");
        return 0;
    }

    printf("Letter grade: ");
    switch (grade / 10) {
        case 10:
        case 9:
            printf("A\n");
            break;
        case 8:
            printf("B\n");
            break;
        case 7:
            printf("C\n");
            break;
        case 6:
            printf("D\n");
            break;
        default:
            printf("F\n");
            break;
    }

    return 0;
}
