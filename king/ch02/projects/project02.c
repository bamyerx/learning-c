/* 
 * Project 2 from Chapter 2 of King: Write a program that computes the volume of
 * a sphere with a 10-meter radius, using the formula v = 4/3*pi*r^3. Write the
 * fraction 4/3 as 4.0f/3.0f.
 */

#include <stdio.h>

#define PI 3.14159f

int main(void)
{
	float radius = 10.0f, volume;

	volume = (4.0f / 3.0f) * PI * radius * radius * radius;

	printf("Volume: %.2f cubic meters\n", volume);

	return 0;
}
