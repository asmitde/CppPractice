#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void SelectionSort(int *arr, int n)
{
	int i, j, k, t;

	for(i = 0; i <= n-2; i++)
	{
		k = i;
		for(j = i+1; j <= n-1; j++)
		{
			if(arr[j] > arr[k])
				k = j;
		}

		t = arr[i];
		arr[i] = arr[k];
		arr[k] = t;
	}
}

int main()
{

	int i, n, *arr;
	system("cls");

	printf("Enter the number of elements to insert: ");
	scanf("%d", &n);

	arr = (int*)malloc(n*sizeof(int));

	for(i=0; i<=n-1; i++)
	{
		printf("Enter #%d: ", i);
		scanf("%d", &arr[i]);
	}

	SelectionSort(arr, n);

	printf("\nSorted array in descending order:\n");
	for(i=0; i<=n-1; i++)
		printf("%d\n", arr[i]);

	getch();
	return 0;
}

/*Output -
Enter the number of elements to insert: 5
Enter #0: 34
Enter #1: 12
Enter #2: 86
Enter #3: 45
Enter #4: 55

Sorted array in descending order:
86
55
45
34
12
*/