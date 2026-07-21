/*
 * Project 5 from Chapter 16 of King: Modify Programming Project 8 from Chapter
 * 5 so that the times are stored in a single array. The elements of the array
 * will be structures, each containing a departure time and the corresponding
 * arrival time. (Each time will be an integer, representing the number of
 * minutes since midnight.) The program will use a loop to search the array for
 * the departure time closest to the time entered by the user.
 *
 * Daily Flight Table:
 * Departure Time    Arrival Time
 *        8:00 AM        10:16 AM
 *        9:43 AM        11:52 AM
 *       11:19 AM         1:31 PM
 *       12:47 PM         3:00 PM
 *        2:00 PM         4:08 PM
 *        3:45 PM         5:55 PM
 *        7:00 PM         9:20 PM
 *        9:45 PM        11:58 PM
 */

#include <stdio.h>
#include <stdlib.h>

#define NFLIGHTS 8

struct flight {
	int departure, arrival;
};

struct flight flight_table[NFLIGHTS] = {{ 480,  616},
	                                    { 583,  712},
										{ 679,  811},
										{ 767,  900},
										{ 840,  968},
										{ 945, 1075},
										{1140, 1280},
										{1305, 1438}};

void print_time(int);

int main(void)
{
    int hour, minute, time, i, n;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minute);
    time = hour * 60 + minute;
	for (i = 0, n = 0; i < NFLIGHTS; i++)
		if (abs(time - flight_table[i].departure) < 
				abs(time - flight_table[n].departure))
			n = i;
    printf("Closest departure time is ");
    print_time(flight_table[n].departure);
    printf(", arriving at ");
    print_time(flight_table[n].arrival);
    printf("\n");

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
