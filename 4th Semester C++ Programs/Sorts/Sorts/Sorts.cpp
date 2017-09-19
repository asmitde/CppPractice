// Sorts.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "sorts.h"
using namespace std;

int main()
{
	int i, n, *arr;
	system("cls");

	cout<<"Enter the number of elements to insert: ";
	cin>>n;

	arr = new int[n];

	for(i = 0; i <= n-1; i++)
	{
		cout<<"Enter #"<<i<<": ";
		cin>>arr[i];
	}

	SelectionSort(arr, n);

	cout<<"\nSelectionSorted array in ascending order:\n";
	for(i=0; i<=n-1; i++)
		cout<<arr[i]<<endl;

	BubbleSort(arr, n);

	cout<<"\nBubbleSorted array in ascending order:\n";
	for(i=0; i<=n-1; i++)
		cout<<arr[i]<<endl;

	InsertionSort(arr, n);

	cout<<"\nInsertionSorted array in ascending order:\n";
	for(i=0; i<=n-1; i++)
		cout<<arr[i]<<endl;

	QuickSort(arr, 0, n - 1);

	cout<<"\nQuickSorted array in ascending order:\n";
	for(i=0; i<=n-1; i++)
		cout<<arr[i]<<endl;

	return 0;
}

