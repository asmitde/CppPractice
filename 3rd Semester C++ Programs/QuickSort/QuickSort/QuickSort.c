#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void QuickSort(int *arr, int l, int r)
{
	int i, j, pv, t;
	
	if(l >= r)
		return;
	
	i = l;
	j = r-1;
	pv = arr[r];

	while(i <= j)
	{
		while(i <= j && pv >= arr[i])
		{
			i = i+1;
		}

		while(j >= i && pv <= arr[j])
		{
			j = j-1;
		}

		if(i < j)
		{
			t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
	}

	t = arr[r];
	arr[r] = arr[i];
	arr[i] = t;

	QuickSort(arr, l, i-1);
	QuickSort(arr, i+1, r);
}

int main()
{
	int *arr, n, i;
	system("cls");

	printf("Enter the total number of elements: ");
	scanf("%d", &n);

	arr = (int*)calloc(n,sizeof(int));

	for(i = 0; i <= n-1; i++)
	{
		printf("Enter element[%d]: ", i);
		scanf("%d", &arr[i]);
	}

	QuickSort(arr, 0, n-1);
	
	for(i = 0; i <= n-1; i++)
		printf("\n%d", arr[i]);

	getch();
	return 0;
}