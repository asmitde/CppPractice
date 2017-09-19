// PuzzleSoln.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <conio.h>

void main()
{
	int i,j,k,ch=0;
	
	for(i=99;i<=32767;i+=10)
	{
		k=1;
		ch=0;
		for(j=2;j<=10;j++)
			if(i%j!=k++)
			{
				ch=1;
				break;
			}

		if(ch==0)
		{
			printf("%d",i);
			break;
		}
	}

	if(ch==1) printf("Number not found");
	getch();
}

