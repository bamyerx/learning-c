/* 
 * Project 2 from Chapter 13 of King: Improve the remind.c program of Section
 * 13.5 in the following ways:
 *      (a) Have the program print an error message and ignore a reminder if the
 *      corresponding day is negative or larger than 31.
 *      (b) Allow the user to enter a day, a 24-hour time, and a reminder. The
 *      printed reminder list should be sorted first by day, then by time.
 *      (c) Have the program print a one-year reminder list. Require the user to
 *      enter days in the form month/day.
 */

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN    60   /* max length of reminder message */

int read_line(char str[], int n);

int main(void)
{
    char reminders[MAX_REMIND][MSG_LEN+12];
    char datetime_str[12], msg_str[MSG_LEN+1];
    int month, day, hour, minute, i, j, num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left -- \n");
            break;
        }

        printf("Enter month/day, 24-hour time, and reminder: ");
        scanf("%2d/%2d %2d:%2d", &month, &day, &hour, &minute);
        if (month == 0)
            break;
        if (month < 1 || month > 12 || day < 0 || day > 31 || 
            hour < 0 || hour > 23 || minute < 0 || minute > 59) {
            printf("Invalid date/time value\n");
            read_line(msg_str, MSG_LEN);    /* clear input buffer */
            continue;
        }
        sprintf(datetime_str, "%02d/%02d %02d:%02d", month, day, hour, minute);
        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++)
            if (strcmp(datetime_str, reminders[i]) < 0)
                break;
        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j-1]);

        strcpy(reminders[i], datetime_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    printf("\n   Day  Time Reminder\n");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminders[i]);

    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}
