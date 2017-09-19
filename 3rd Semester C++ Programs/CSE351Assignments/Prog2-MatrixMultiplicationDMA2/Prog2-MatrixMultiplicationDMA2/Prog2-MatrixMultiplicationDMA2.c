#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void matprod(int*,int*,int*,int,int,int);
void readmatrix(int*,int,int);
void printmatrix(int*,int,int);

void main()
{
	int *A, *B, *C, p, q, r;

	printf("Enter the values of p. q & r in C[p][r]=A[p][q]*B[q][r]: ");
	scanf("%d %d %d",&p,&q,&r);

	A=(int*)calloc(p*q,sizeof(int));
	B=(int*)calloc(q*r,sizeof(int));
	C=(int*)calloc(p*r,sizeof(int));

	printf("\nMatrix A:\n");
	readmatrix(A,p,q);

	printf("\nMatrix B:\n");
	readmatrix(B,q,r);

	matprod(A,B,C,p,q,r);

	printf("\nMatrix A:\n");
	printmatrix(A,p,q);
	printf("\nMatrix B:\n");
	printmatrix(B,q,r);
	printf("\nMatrix C=A*B:\n");
	printmatrix(C,p,r);

	getch();
}

void matprod(int *X,int *Y,int *Z,int p,int q,int r)
{
	int i,j,k;
	for(i=0;i<p;i++)
		for(j=0;j<r;j++)
		{
			*(Z+i*r+j)=0;
			for(k=0;k<q;k++)
				*(Z+i*r+j)+= *(X+i*q+k) * *(Y+k*r+j);
		}
}

void readmatrix(int *X,int x,int y)
{
	int i,j;

	for(i=0;i<x;i++)
		for(j=0;j<y;j++)
		{
			printf("Enter element[%d][%d]: ",i,j);
			scanf("%d",(X+i*y+j));
		}
}

void printmatrix(int *X,int x,int y)
{
	int i,j;

	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
			printf("%d\t",*(X+i*y+j));
		printf("\n");
	}
}