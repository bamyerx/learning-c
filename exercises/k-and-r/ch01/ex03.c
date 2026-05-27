/**
 * Fahrenheit-Celsius table from chapter 1 of K & R.
 **/

#include <stdio.h>

int main(void)
{
   float fahr, celsius;
   float lower, upper, step;

   lower = 0;
   upper = 300;
   step = 20;

   printf("Fahrenheit to Celsius Conversion Table\n");
   printf("Fahrenheit\tCelsius\n");

   fahr = lower;
   while (fahr <= upper) {
      celsius = (5.0 / 9.0) * (fahr - 32.0);
      printf("%10.0f\t%7.1f\n", fahr, celsius);
      fahr = fahr + step;
   }
}
