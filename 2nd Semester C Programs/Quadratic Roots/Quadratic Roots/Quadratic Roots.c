/*Assignment 1 > Program 3: Program to calculate roots of a quadratic equation*/
/*Author: Asmit De    Date: 24.01.2011*/

#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
	float a,b,c,d,r1,r2;

	printf("Enter the coefficient of x^2 (a): "); scanf("%f",&a);
	printf("Enter the coefficient of x (b): "); scanf("%f",&b);
	printf("Enter the coefficient of 1 (c): "); scanf("%f",&c);

	d=b*b-4*a*c;

	if(d>=0)
	{
		r1=(-b+sqrt(d))/(2*a);
		r2=(-b-sqrt(d))/(2*a);

		printf("\nRoot 1 = %.2f\nRoot 2 = %.2f",r1,r2);
	}
	else
	{
		printf("\nRoot 1 = %.2f + i%.2f",-b/(2*a),sqrt(-d)/(2*a));
		printf("\nRoot 2 = %.2f - i%.2f",-b/(2*a),sqrt(-d)/(2*a));
	}

	getch();
}

