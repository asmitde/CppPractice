// Insertion Sort.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <conio.h>


void main()
{
	int arr[100],n,i,j,key;

	printf("Enter the value of n: ");
	scanf("%d",&n);

	for(i=0;i<=n-1;i++)
	{
		printf("Enter element[%d]: ",i);
		scanf("%d",&arr[i]);
	}

	for(i=1;i<=n-1;i++)
	{
		key=arr[i];
		j=i-1;
		while(arr[j]>key && j>=0)
		{
			arr[j+1]=arr[j];
			j--;
		}

		arr[j+1]=key;
	}

	printf("\nSorted array:");
	for(i=0;i<=n-1;i++)
		printf("\nElement[%d]: %d",i,arr[i]);

	getch();

}

