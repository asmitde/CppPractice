// Recursion_ReverseArray.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;

void ReverseArray(int A[50], int i, int n)
{
	if(n>1)
	{
		int t=A[i];
		A[i]=A[i+n-1];
		A[i+n-1]=t;

		ReverseArray(A,i+1,n-2);
	}
}

int main(void)
{
	int arr[50], n;

	cout<<"How many numbers will you enter? ";
	cin>>n;

	for(int i=0; i<=n-1; i++)
	{
		cout<<"Enter element #"<<i<<": ";
		cin>>arr[i];
	}

	ReverseArray(arr,0,n);
	cout<<"\nReverse array:\n";
	for(int i=0; i<=n-1; i++)
	{
		cout<<"Element #"<<i<<": "<<arr[i]<<endl;
	}

	return 0;
}

