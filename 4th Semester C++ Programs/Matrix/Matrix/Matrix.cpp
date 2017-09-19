#include <iostream>
#include <string>
#include <cstdlib>
#include "matrix.h"

int main()
{
//	Matrix<int> m1(3), m2(2), m3(2), m4(2), m5(2), m6(2,3); Matrix<int> m7(2);
	
	cout<<"Enter dimensions of m1: "; int m,n; cin>>m>>n;
	Matrix<int> m1(m, n);
	cout<<"Enter values of m1:\n";

	cin>>m1;
	cout<<endl; cout<<m1; cout<<endl;

/*	cout<<m1.minor(1, 1);
	if(m1.isDiagonal()) cout<<"Diag";

	system("pause");*/
//	cout<<"Enter dimensions of m2: "; cin>>m>>n;
	Matrix<int> m2(m, n);
	cout<<"Enter values of m2:\n";

	cin>>m2;
	cout<<endl<<m2; cout<<endl;

	Matrix<int> m3(m,n);
	m3 = m1 + m2;
	Matrix<int> m4(m,n);
	m4 = m1 - m2;
	Matrix<int> m5(m,n);
	m5 = m1 * m2;
	cout<<"\nsum:\n"<<m3;
	cout<<"\ndiff:\n"<<m4;
	cout<<"\nprod:\n"<<m5;
/*	cout<<endl<<"Enter values for m6:\n";
	cin>>m6;
	cout<<endl;
	cout<<m6.transpose();
	cout<<endl;
	m7 = m1.inverse();
	cout<<endl<<m1.determinant();
	system("pause");*/
	return 0;
}