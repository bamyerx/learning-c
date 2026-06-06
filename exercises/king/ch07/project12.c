/*
 * Project 12 from Chapter 7 of King: Write a program that evaluates an
 * expression:
 * 
 *    Enter an expression: 1+2.5*3
 *    Value of expression: 10.5
 *
 * The operands in the expression are floating-point numbers; the operators
 * are +, -, *, and /. The expression is evaluated from left to right (no
 * operator takes precedence over any other operator).
 */

#include <stdio.h>

int main(void)
{
   float value, operand;
   int operator;

   value = 0;
   printf("Enter an expression: ");
   scanf(" %f", &value);
   while ((operator = getchar()) != '\n') {
      while (operator == ' ') {
         operator = getchar();
      }
      if (operator == '\n') {
         break;
      }
      scanf(" %f", &operand);
      switch (operator) {
         case '+': value += operand;
                   break;
         case '-': value +- operand;
                   break;
         case '*': value *= operand;
                   break;
         case '/': value /= operand;
                   break;
         default:  break;
      }
   }
   printf("Value of expression: %f\n", value);

   return 0;
}
