
#include <stdio.h>
#include <conio.h>

int calc_hcf(int x,int y)
{
	if(y==0)
		return x;

	calc_hcf(y,y%x);
}

void main()
{
	int a,b,hcf;

	printf("Enter 2 numbers: ");
	scanf("%d %d",&a,&b);

	if(a>b)
	{
		a=a+b;
		b=a-b;
		a=a-b;
	}

	hcf=calc_hcf(a,b);
	
	printf("\nHCF of %d & %d is %d",a,b,hcf);

	getch();
}

