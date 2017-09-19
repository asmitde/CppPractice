// Frequency.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <conio.h>

void main()
{
	int arr[50], n, i, j, t, val, currentVal, occurrence;

	printf("How many numbers will you enter? "); scanf("%d",&n);
	for(i=0; i<=n-1; i++)
	{
		printf("Enter #%d: ",i+1);
		scanf("%d",&arr[i]);
	}

	for(i=0;i<=n-2;i++)
	{
		for(j=i+1;j<=n-1;j++)
			if(arr[i]>arr[j])
			{
				t=arr[i];
				arr[i]=arr[j];
				arr[j]=t;
			}
	}
/*	for(i=0;i<=n-1;i++)
		printf("\n#%d: %d",i+1,arr[i]);
*/
	printf("\nValue\tFrequency");

	val = arr[0];
	occurrence = 1;
	for(i=1;i<=n-1;i++)
	{
		currentVal = arr[i];
		if(currentVal == val)
			occurrence+=1;
		else
		{
			printf("\n%d\t%d",val,occurrence);
			val = currentVal;
			occurrence = 1;
		}
	}
	printf("\n%d\t%d",val,occurrence);

	getch();
}