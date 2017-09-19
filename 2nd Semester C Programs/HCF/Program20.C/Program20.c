#include <stdio.h>
#include <conio.h>

void main()
{
	int a,b,hcf,i;

	printf("Enter 2 numbers: ");
	scanf("%d %d",&a,&b);

	if(a>b)
	{
		a=a+b;
		b=a-b;
		a=a-b;
	}

	hcf=a;
	
	for(i=1;i<=a;i++)
	{
		if(a%i==0)
			hcf=a/i;
		else
			continue;

		if(b%hcf==0)
			break;
	}

	printf("\nHCF of %d and %d is %d",a,b,hcf);

	getch();
}

