/*
 * Project 5 from Chapter 23 of King: Suppose that money is deposited into a
 * savings account and left for t years. Assume that the annual interest rate is
 * r and that interest is compounded continuously. The formula A(t) = Pe^(rt)
 * can be used to calculated the final value of the account, where P is the
 * original amount deposited. For example $1000 left on deposit for 10 years at
 * 6% interest would be worth $1000*e^(0.06*10) = $1,822.12. Write a program
 * that displays the result of this calculation after prompting the user to
 * enter the original amount deposited, the interest rate, and the number of
 * years.
 */

#include <math.h>
#include <stdio.h>

int main(void)
{
	double p, r, t, round_nearest(double, int);

	printf("Enter principal: ");
	scanf("%lf", &p);
	printf("Enter interest rate: ");
	scanf("%lf", &r);
	printf("Enter time in years: ");
	scanf("%lf", &t);

	printf("Resulting balance: $%.2lf\n", 
		   round_nearest(p * exp(r / 100 * t), 2));
	
	return 0;
}

double round_nearest(double x, int n)
{
	double p = pow(10.0, n);

	return x < 0.0 ? ceil(x * p - 0.5) / p : floor(x * p + 0.5) / p;
}
