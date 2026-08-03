/*
 * Project 13 from Chapter 22 of King: Modify Programming Project 8 from Chapter
 * 5 so that the program obtains departure and arrival times from a file named
 * flights.dat. Each line of the file will contain a departure time followed by
 * an arrival time, with one or more spaces separating the two. Times will be
 * expressed using the 24-hour clock.
 */

#include <stdio.h>
#include <stdlib.h>

#define MSM(hour,minute) ((hour) * 60 + (minute))
#define MAXLINE 100

struct flight {
	int depart_hour;
	int depart_minute;
	int arrive_hour;
	int arrive_minute;
};

void print_time(int);

int main(void)
{
	FILE *fp;
	char line[MAXLINE];
    int hour, minute, time;
	struct flight current, best;

	if ((fp = fopen("flights.dat", "r")) == NULL) {
		fprintf(stderr, "Error: flights.dat can't be opened\n");
		exit(EXIT_FAILURE);
	}

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minute);
    time = MSM(hour, minute);
	best.depart_hour = -1;    /* sentinel for first loop */
	while (fgets(line, MAXLINE, fp) != NULL) {
		if (sscanf(line, "%d:%d %d:%d", 
					&current.depart_hour, 
					&current.depart_minute,
					&current.arrive_hour,
					&current.arrive_minute) != 4) {
			fprintf(stderr, "Error: formatting error in flights.dat\n");
			exit(EXIT_FAILURE);
		}
		if (best.depart_hour < 0)
			best = current;
		if (abs(time - MSM(current.depart_hour, current.depart_minute)) <
			abs(time - MSM(best.depart_hour, best.depart_minute)))
			best = current;
	}
	printf("Closest departure time is ");
	print_time(MSM(best.depart_hour, best.depart_minute));
	printf(", arriving at ");
	print_time(MSM(best.arrive_hour, best.arrive_minute));
	printf("\n");

	fclose(fp);
	return 0;
}

void print_time(int minutes_since_midnight)
{
    int hour, minute;

    hour = minutes_since_midnight / 60;
    minute = minutes_since_midnight % 60;
    printf("%d:%02d %s", (hour % 12 == 0) ? 12 : hour % 12,
                        minute,
                        (hour < 12) ? "a.m." : "p.m.");
}
