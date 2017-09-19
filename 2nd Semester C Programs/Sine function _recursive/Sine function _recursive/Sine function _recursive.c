// Sine function _recursive.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <conio.h>

float sine(float x,int n,int sn);

float s=0;

void main()
{
	float x; int n,sn;

	printf("Enter the value of x (in radians): "); scanf("%f",&x);
	printf("Enter the nunber of terms n: "); scanf("%d",&n);

	if(n%2==0)
		sn=-1;
	else
		sn=1;

	sine(x,n*2-1,sn);

	printf("\nSin(%f) = %f",x,s);
	
	getch();
}

float sine(float x,int n,int sn)
{
	float ti;
	if(n==1) 
	{
		s=x;
		return x;
	}

	ti=(x*x)/(n*(n-1))*sine(x,n-2,-sn);
	s+=sn*ti;
	return ti;
}

