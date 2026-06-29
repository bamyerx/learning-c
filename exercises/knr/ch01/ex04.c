/**
 * Celsius-Fahrenheit conversion table.
 **/

#include <stdio.h>

int main(void)
{
   float fahr, celsius;
   float lower, upper, step;

   lower = -20;
   upper = 150;
   step = 10;

   printf("Celsius to Fahrenheit Conversion Table\n");
   printf("Celsius\tFahrenheit\n");

   celsius = lower;
   while (celsius <= upper) {
      fahr = (9.0 / 5.0) * (celsius + 32.0);
      printf("%7.0f\t%10.1f\n", celsius, fahr);
      celsius = celsius + step;
   }
}
