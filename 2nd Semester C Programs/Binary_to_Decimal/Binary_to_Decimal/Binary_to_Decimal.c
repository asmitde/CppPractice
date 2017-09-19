// Binary_to_Decimal.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <conio.h>
#include <math.h>

int BtoD(int x)
{
	int sum=0,c=0;

	do
	{
		sum+=x%10*pow(2,c++);
		x/=10;
	}while(x);

	return (sum);
}

void main()
{
	int binnum,decnum;

	printf("Enter the number: ");
	scanf("%d",&binnum);

	decnum = BtoD(binnum);

	printf("\nBinary: %d = Decimal: %d",binnum,decnum);

	getch();
}

