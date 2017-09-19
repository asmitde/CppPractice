// perfect number.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <conio.h>
void main()
{
	int n,i,s=0;
	for(i=1;i<=3;i++)
		if(6%i==0)
			s+=i;
	if(s==6)
		printf("pn");
	else printf("npn");
	getch();
}

