// BigNumber.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "bignumbr.h"
using namespace std;

int main()
{
	BigNumber b1, b2, b3;

	cout<<"Enter 1st number: ";
	cin>>b1;
	cout<<"Enter 2nd number: ";
	cin>>b2;
	
	b3 = b1 + b2;
	cout<<endl<<"Sum = "<<b3;
	
	b3 = b1 - b2;
	cout<<endl<<"Difference = "<<b3;

	b3 = b1 * b2;
	cout<<endl<<"Product = "<<b3;

	cout<<endl;
	return 0;
}

