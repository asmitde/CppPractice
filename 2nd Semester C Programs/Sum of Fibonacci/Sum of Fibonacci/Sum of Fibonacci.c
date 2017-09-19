// Sum of Fibonacci.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <conio.h>

void main()
{
	int a=0,b=1,c,s=a+b,i;

	for(i=3;i<=8;i++)
	{
		c=a+b;
		s+=c;
		a=b;
		b=c;
	}

	printf("Sum = %d",s);

	getch();
}

