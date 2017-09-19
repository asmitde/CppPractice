#include <stdio.h>
#include <conio.h>

void main()
{
	int i,j,k,n;

	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
		{
			if(j==i) continue;

			for(k=1;k<=3;k++)
			{
				if(k==j || k==i) continue;

				n=100*i+10*j+k;
				printf("\n%d",n);
			}
		}

	getch();
}