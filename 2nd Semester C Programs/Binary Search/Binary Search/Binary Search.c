#include <stdio.h>
#include <conio.h>

int arr[50],num; // Global declaration of the array and number to be searched

void BSearch(int low,int high)
{
	int mid=(high+low)/2;

	if(low>=high) // Breaking condition
	{
		printf("\n%d is not present in array",num);
		return;
	}
	else if(arr[mid]==num) // Breaking condition
	{
		printf("\n%d is present in array",num);
		return;
	}
	else if(arr[mid]<num)
		BSearch(mid+1,high);
	else if(arr[mid]>num)
		BSearch(low,mid-1);
}

void ASSort(int n)
{
	int i,j,t;
	for(i=0;i<=n-2;i++)
		for(j=i+1;j<=n-1;j++)
			if(arr[i]>arr[j])
			{
				t=arr[i];
				arr[i]=arr[j];
				arr[j]=t;
			}
}

void main()
{
	int n,i;
	
	printf("How many numbers will you enter? (<=50) ");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("Enter #%d ",i+1);
		scanf("%d",&arr[i]);
	}

	printf("\nEnter number to search ");
	scanf("%d",&num);
	ASSort(n);
	BSearch(0,n-1); // Call to the Binary Search function
	
	getch();
}