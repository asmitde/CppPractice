
#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
	int num,n,r,d=1,s=0;

	printf("Enter a number: ");
	scanf("%d",&num);

	n=num;

	while(n/=10)
		d++;

	n=num;

	while(n)
	{
		r=n%10;
		n/=10;
		s+=pow((float)r,d);
	}

	if(s==num)
		printf("%d is a Armstrong Number",num);
	else
		printf("%d is not a Armstrong Number",num);

	getch();
}

