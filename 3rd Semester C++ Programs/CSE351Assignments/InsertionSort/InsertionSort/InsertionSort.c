#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void InsertionSort(int *arr, int n)
{
	int i, j, key;

	for(i = 1; i <= n-1; i++)
	{
		key = arr[i];
		j = i-1;
		while(arr[j] > key && j >= 0)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

int main()
{

	int i, n, *arr;
	system("cls");

	printf("Enter the number of elements to insert: ");
	scanf("%d", &n);

	arr = (int*)malloc(n*sizeof(int));

	for(i = 0; i <= n-1; i++)
	{
		printf("Enter #%d: ", i);
		scanf("%d", &arr[i]);
	}

	InsertionSort(arr, n);

	printf("\nSorted array in ascending order:\n");
	for(i=0; i<=n-1; i++)
		printf("%d\n", arr[i]);

	getch();
	return 0;
}

/*Output -
Enter the number of elements to insert: 5
Enter #0: 34
Enter #1: 98
Enter #2: 12
Enter #3: 55
Enter #4: 46

Sorted array in ascending order:
12
34
46
55
98
*/