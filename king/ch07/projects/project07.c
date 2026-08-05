/*
 * Project 7 from Chapter 7 of King: Modify Programming Project 6 from Chapter
 * 3 so that the user may add, subtract, multiply, or divide two fractions (by
 * entering either +, -, *, or / between the fractions).
 */

#include <stdio.h>

int main(void)
{
   int num1, denom1, num2, denom2, op, result_num, result_denom;

   printf("Enter two fractions separated by +, -, *, or / symbol: ");
   scanf("%d / %d %c %d / %d", &num1, &denom1, &op, &num2, & denom2);

   if (op == '+') {
      result_num = num1 * denom2 + num2 * denom1;
      result_denom = denom1 * denom2;
   } else if (op == '-') {
      result_num = num1 * denom2 - num2 * denom1;
      result_denom = denom1 * denom2;
   } else if (op == '*') {
      result_num = num1 * num2;
      result_denom = denom1 * denom2;
   } else if (op == '/') {
      result_num = num1 * denom2;
      result_denom = denom1 * num2;
   } else {
      printf("Invalid input\n");
      return 0;
   }
   printf("The result is %d/%d\n", result_num, result_denom);

   return 0;
}
