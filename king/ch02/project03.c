/*
 * Project #3 from chapter 2 of C Programming by K.N. King.
 *
 * Computes the volume of a sphere with a user-defined radius.
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
