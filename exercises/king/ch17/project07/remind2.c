/*
 * Project 7 from Chapter 17 of King: Modify the remind2.c program of Section
 * 17.2 so that each element of the reminders array is a pointer to a vstring
 * structure rather than a pointer to an ordinary string.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN 60      /* max length of reminder message */

struct vstring {
	int len;
	char str[];
};

int read_line(char str[], int n);

int main(void)
{
	struct vstring *reminders[MAX_REMIND];
	char day_str[3], msg_str[MSG_LEN+1];
	int day, len, i, j, num_remind = 0;

	for (;;) {
		if (num_remind == MAX_REMIND) {
			printf("-- No space left --\n");
			break;
		}

		printf("Enter day and reminder: ");
		scanf("%2d", &day);
		if (day == 0)
			break;
		sprintf(day_str, "%2d", day);
		len = read_line(msg_str, MSG_LEN) + 2;

		for (i = 0; i < num_remind; i++)
			if (strcmp(day_str, reminders[i]->str) < 0)
				break;
		for (j = num_remind; j > i; j--)
			reminders[j] = reminders[j-1];

		reminders[i] = malloc(sizeof(struct vstring) + len + 1);
		if (reminders[i] == NULL) {
			printf("-- No space left --\n");
			break;
		}
		reminders[i]->len = len + 1;

		strcpy(reminders[i]->str, day_str);
		strcat(reminders[i]->str, msg_str);

		num_remind++;
	}

	printf("\nDay Reminder\n");
	for (i = 0; i < num_remind; i++)
		printf(" %s\n", reminders[i]->str);

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
