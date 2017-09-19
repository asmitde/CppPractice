// Recursion_LinearSum.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;

int LinearSum(int A[50], int n)
{
	if(n==1)
		return A[0];
	else
		return LinearSum(A,n-1) + A[n-1];
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

	cout<<"\nSum of the "<<n<<" numbers is "<<LinearSum(arr,n)<<endl;

	return 0;
}

