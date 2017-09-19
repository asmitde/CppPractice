// Swap.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <conio.h>

void numswap(int *var1,int *var2)
{
	int temp;

	temp=*var1;
	*var1=*var2;
	*var2=temp;
}

void main()
{
	int a,b;

	printf("Enter two numbers (a b): ");
	scanf("%d %d",&a,&b);

	numswap(&a,&b);

	printf("\nSwapped: a=%d b=%d",a,b);

	getch();
}