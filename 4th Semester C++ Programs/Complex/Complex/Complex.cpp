// Complex.cpp : Defines the entry point for the console application.
#include <iostream>
#include "complex.h"
using namespace std;

int main()
{
	Complex c1, c2, c3, c4, c5;
	cout<<"Enter real and imaginary for c1: ";
	cin>>c1;

	cout<<"Enter real and imaginary for c2: ";
	cin>>c2;
	c3 = c1 + c2;
	cout<<endl<<"Sum: "<<c3;
	c4 = c1 - c2;
	cout<<endl<<"Diff: "<<c4;
	c5 = c1 * c2;
	cout<<endl<<"Prod: "<<c5;
	return 0;
}