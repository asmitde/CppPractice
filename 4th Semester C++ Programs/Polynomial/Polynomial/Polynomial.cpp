/*
 * Polynomial.cpp
 *
 *  Created on: Jan 21, 2012
 *      Author: asmit
 */

#include "polynomial.h"
using namespace std;

int main()
{
	Polynomial<int> p1, p2, p3, p4, p5;

	cout<<"P1:\n";
	cout<<"Enter no of terms: ";
	int n; cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cout<<"Enter power & coefficient: ";
		int p, c; cin>>p>>c;
		p1.addTerm(c, p);
	}
	cout<<"P1 = "<<p1<<endl;

	cout<<"P2:\n";
	cout<<"Enter no of terms: ";
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cout<<"Enter power & coefficient: ";
		int p, c; cin>>p>>c;
		p2.addTerm(c, p);
	}
	cout<<"P2 = "<<p2<<endl;
	
	p3 = p1 + p2;
	p4 = p1 - p2;
	p5 = p1 * p2;

	cout<<endl<<"P3 = P1 + P2 = "<<p3;
	cout<<endl<<"P4 = P1 - P2 = "<<p4;
	cout<<endl<<"P4 = P1 * P2 = "<<p5;
	cout<<endl;
	return 0;
}
