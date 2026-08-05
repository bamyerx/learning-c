/*
 * Project 8 from Chapter 5 of King: The following table shows the daily flights
 * from one city to another:
 *
 *     Departure Time    Arrival Time
 *         8:00 AM         10:16 AM
 *         9:43 AM         11:52 AM
 *        11:19 AM          1:31 PM
 *        12:47 PM          3:00 PM
 *         2:00 PM          4:08 PM
 *         3:45 PM          5:55 PM
 *         7:00 PM          9:20 PM
 *         9:45 PM         11:58 PM
 *
 * Write a program that asks the user to enter a time (expressed in hours and
 * minutes, using the 24-hour clock). The program then displays the departure
 * and arrival times for the flight whose departure time is closest to that
 * entered by the user:
 *
 *     Enter a 24-hour time: 13:15
 *     Closest departure time is 12:47 p.m., arriving at 3:00 p.m.
 */

#include <stdio.h>

// Macro definitions for departure times as minutes since midnight
#define DEPARTURE_1 480
#define DEPARTURE_2 583
#define DEPARTURE_3 679
#define DEPARTURE_4 767
#define DEPARTURE_5 840
#define DEPARTURE_6 945
#define DEPARTURE_7 1140
#define DEPARTURE_8 1305

int main(void)
{
    int hour, minute, minutes_since_midnight;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minute);
    minutes_since_midnight = hour * 60 + minute;

    printf("Closest departure time is ");
    if (minutes_since_midnight <= (DEPARTURE_1 + DEPARTURE_2) / 2) {
        printf("8:00 a.m., arriving at 10:16 a.m.\n");
    } else if (minutes_since_midnight <= (DEPARTURE_2 + DEPARTURE_3) / 2) {
        printf("9:43 a.m., arriving at 11:52 a.m.\n");
    } else if (minutes_since_midnight <= (DEPARTURE_3 + DEPARTURE_4) / 2) {
        printf("11:19 a.m., arriving at 1:31 p.m.\n");
    } else if (minutes_since_midnight <= (DEPARTURE_4 + DEPARTURE_5) / 2) {
        printf("12:47 p.m., arriving at 3:00 p.m.\n");
    } else if (minutes_since_midnight <= (DEPARTURE_5 + DEPARTURE_6) / 2) {
        printf("2:00 p.m., arriving at 4:08 p.m.\n");
    } else if (minutes_since_midnight <= (DEPARTURE_6 + DEPARTURE_7) / 2) {
        printf("3:45 p.m., arriving at 5:55 p.m.\n");
    } else if (minutes_since_midnight <= (DEPARTURE_7 + DEPARTURE_8) / 2) {
        printf("7:00 p.m., arriving at 9:20 p.m.\n");
    } else {
        printf("9:45 p.m., arriving at 11:58 p.m.\n");
    }

    return 0;
}
