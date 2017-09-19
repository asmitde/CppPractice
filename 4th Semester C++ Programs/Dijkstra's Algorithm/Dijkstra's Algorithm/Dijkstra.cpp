#include <iostream>
#include <fstream>
#include <string>
#include "matrix.h"
#include "dijkstra.h"
using namespace std;

int main()
{
	cout<<"Enter the number of nodes in the graph: ";
	int n; cin>>n;

	Matrix<int> wtMat(n);
	cout<<endl<<"Enter the Weight Matrix of the graph:"<<endl;
	cin>>wtMat;

/*	if(!wtMat.isSymmetric())
	{
		cout<<endl<<"Error: Invalid matrix (Non-Symmetric Matrix entered)";
		system("pause");
		exit(1);
	}*/

	cout<<endl<<"Enter the index of the source and destination node in the Weight Matrix: ";
	int s, d; cin>>s>>d;

	Dijkstra dj(wtMat._matrix, n, s);
	int minPtWt = dj.getMinimumPathWeight(d);

	cout<<endl<<"Minimum path weight from source to destination = "<<minPtWt<<endl;

	return 0;
}