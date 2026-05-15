/* Project #2 from chapter 2 of C Programming by K.N. King.
 *
 * Computes the volume of a sphere with a 10-meter radius.
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
