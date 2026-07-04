/*
 * Project 2 from Chapter 11 of King: Modify Programming Project 8 from Chapter
 * 5 so that it includes the following function:
 *
 *      void find_closest_flight(int desired_time,
 *                               int *departure_time,
 *                               int *arrival_time);
 *
 * This function will find the flight whose departure time is closest to
 * desired_time (expressed in minutes since midnight). It will store the
 * departure and arrival times of this flight (also expressed in minutes since
 * midnight) in the variables pointed to by departure_time and arrival_time,
 * respectively.
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
#include <stdlib.h>     /* for abs */

#define NFLIGHTS 8

void find_closest_flight(int, int *, int *);
void print_time(int);

int main(void)
{
    int desired_time, departure_time, arrival_time, hour, minute;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minute);
    desired_time = hour * 60 + minute;
    find_closest_flight(desired_time, &departure_time, &arrival_time);

    printf("Closest departure time is ");
    print_time(departure_time);
    printf(", arriving at ");
    print_time(arrival_time);
    printf("\n");

    return 0;
}

void find_closest_flight(int desired_time, 
                         int *departure_time, 
                         int *arrival_time)
{
    int i, n,
        departures[NFLIGHTS] = {480, 583, 679, 767, 840, 945, 1140, 1305},
        arrivals[NFLIGHTS] = {616, 712, 811, 900, 968, 1075, 1280, 1438};

    for (i = 0, n = 0; i < NFLIGHTS; i++)
        if (abs(desired_time - departures[i]) < 
                abs(desired_time - departures[n]))
            n = i;
    *departure_time = departures[n];
    *arrival_time = arrivals[n];
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
