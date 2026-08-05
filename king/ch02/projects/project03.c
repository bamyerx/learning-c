/*
 * Project 3 from Chapter 2 of King: Modify the program of Programming Project 2
 * so that it prompts the user to enter the radius of the sphere.
 */

#include <stdio.h>

#define PI 3.14159f

int main(void)
{
    float radius, volume;

    printf("Enter the radius of the sphere in meters: ");
    scanf("%f", &radius);

    volume = (4.0f / 3.0f) * PI * radius * radius * radius;

    printf("Volume: %.2f cubic meters\n", volume);

    return 0;
}
