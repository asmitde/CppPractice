// Fibonacci_recursion.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <conio.h>

void fibonacci(int a,int b,int n)
{
	if(n==1)
	{
		printf("%d",b);
		return;
	}
	
		printf("%d ",b);
		fibonacci(b,a+b,n-1);
}


void main()
{
	int n;

	printf("Enter a number: "); scanf("%d",&n);

	fibonacci(1,0,n);

	getch();
}

