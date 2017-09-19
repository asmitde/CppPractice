
#include <stdio.h>
#include <conio.h>

void main()
{
	int num,s=0,d,rev=0;

	printf("Enter a number: ");
	scanf("%d",&num);

	while(num)
	{
		d=num%10;
		num/=10;
		s+=d;
		rev=rev*10+d;
	}

	printf("\nSum of digits = %d",s);
	printf("\nReverse = %d",rev);

	getch();
}

