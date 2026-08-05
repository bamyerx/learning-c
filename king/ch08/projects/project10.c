/*
 * Project 10 from Chapter 8 of King: Modify Programming Project 8 from chapter
 * 5 so that the departure times are stored in an array and the arrival times
 * are stored in a second array. (The times are integers, representing the 
 * number of minutes since midnight.) The program will use a loop to search the
 * array of departure times for the one closest to the time entered by the user.
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

#define N_FLIGHTS 8

// Macro definitions for departure times as minutes since midnight

int main(void)
{
   int departures[N_FLIGHTS] = {480, 583, 679, 767, 840, 945, 1140, 1305};
   int arrivals[N_FLIGHTS] = {616, 712, 811, 900, 968, 1075, 1280, 1438};
   
   int hour, minute, time, i, n;

   printf("Enter a 24-hour time: ");
   scanf("%d:%d", &hour, &minute);
   time = hour * 60 + minute;
   
   for (i = 0, n = 0; i < N_FLIGHTS; i++) {
      if (abs(time - departures[i]) < abs(time - departures[n]))
         n = i;
   }

   printf("Closest departure time is ");
   if (departures[n] / 60 < 12) {
      printf("%d:%02d a.m., arriving at ", 
            departures[n] / 60, departures[n] % 60);
   } else {
      printf("%d:%02d p.m., arriving at ", 
            departures[n] / 60 - 12, departures[n] % 60);
   }
   if (arrivals[n] / 60 < 12)
      printf("%d:%02d a.m.\n", arrivals[n] / 60, arrivals[n] % 60);
   else
      printf("%d:%02d p.m.\n", arrivals[n] / 60 - 12, arrivals[n] % 60);

   return 0;
}
