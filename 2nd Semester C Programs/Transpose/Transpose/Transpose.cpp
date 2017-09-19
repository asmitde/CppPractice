// Transpose.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include<conio.h>

void main()
{
	int arr[3][3],i,j,t;

	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}

	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			if(i!=j && i<j)
			{
				t=arr[i][j];
				arr[i][j]=arr[j][i];
				arr[j][i]=t;
			}
		}
	}

	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}

	getch();
}

