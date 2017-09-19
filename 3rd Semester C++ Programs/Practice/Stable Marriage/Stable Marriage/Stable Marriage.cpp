// Stable Marriage.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdio>

using namespace std;

struct pos
{
	int bg;
	int gb;
	int sum;
};

int main(void)
{
	int n,pair=0;

	cout<<"Enter the number of couples: ";
	cin>>n;

	//Creating empty matrix for couples
	pos **smm=new pos *[n];
	for(int i=0;i<n;i++)
	{
		smm[i]=new pos[n];
	}

	//Creating empty array for storing couples
	int **coup=new int *[2];
	for(int i=0;i<2;i++)
		coup[i]=new int[n];

	//Entering preference list of boys
	for(int i=0;i<n;i++)
	{
		cout<<"Preference list of B"<<(i+1)<<" - "<<endl;
		for(int j=0;j<n;j++)
		{
			cout<<"G"<<(j+1)<<": ";
			cin>>smm[i][j].bg;
		}
	}

	//Entering preference list of girls
	for(int i=0;i<n;i++)
	{
		cout<<"Preference list of G"<<(i+1)<<" - "<<endl;
		for(int j=0;j<n;j++)
		{
			cout<<"B"<<(j+1)<<": ";
			cin>>smm[j][i].gb;
		}
	}

	//Adding bg and gb
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			smm[i][j].sum=smm[i][j].bg+smm[i][j].gb;
		}
	}

	// For debugging purposes only - printing the matrix
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<smm[i][j].sum<<" ";
		}
		cout<<endl;
	}

	////////////////////////////////////////////////////////////////////////////////////
	// Solving the matrix

	do{
	for(int i=0;i<n;i++)
	{
		int least=smm[i][0].sum,posi=i,posj=0,flag=0;

		for(int j=0;j<n;j++) // Storing the least element of the i-th row in least
			if(smm[i][j].sum<least)
			{
				least=smm[i][j].sum;
				posi=i;
				posj=j;
			}

		for(int k=0;k<n;k++)
			if(smm[k][posj].sum<least)
			{
				flag=1;
				break;
			}

		if(flag==0)
		{
			coup[0][pair]=posi;
			coup[1][pair]=posj;
			pair++;

			for(int i=0;i<n;i++)
			{
				smm[posi][i].sum=2*n+1;
				smm[i][posj].sum=2*n+1;
			}
		}
	}
	}while(pair<n);

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			

	return 0;
}