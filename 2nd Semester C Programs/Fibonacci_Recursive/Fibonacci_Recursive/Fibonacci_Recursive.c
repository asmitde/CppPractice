// Fibonacci_Recursive.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <conio.h>

int fibonacci(int n)
{
	
	if(n==1 || n==2)
		return 1;
	else
		return(fibonacci(n-1)+fibonacci(n-2));

}

void main()
{
	int n,x;

	printf("Enter number of terms: ");
	scanf("%d",&n);

	x= fibonacci(n);
	
	printf("%d",x);
	getch();

}

