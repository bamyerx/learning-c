/*
 * Exercise 1-15 from K & R: Rewrite the temperature conversion program of
 * Section 1.2 to use a function for conversion.
 */

#include <stdio.h>

float convert(float f);

int main(void)
{
   float fahr, celsius;
   float lower, upper, step;

   lower = 0.0f;
   upper = 300.0f;
   step = 20.0f;

   fahr = lower;
   while (fahr <= upper) {
      printf("%3.0f %6.1f\n", fahr, convert(fahr));
      fahr = fahr + step;
   }

   return 0;
}

float convert(float f) {
   float c = (5.0f / 9.0f) * (f - 32.0f);
   return c;
}
