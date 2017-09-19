// Palindrome.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <conio.h>
#include <string.h>

void main()
{

	char str[80]; int i,l,flag=0;

	gets(str);

	l=strlen(str);

	for(i=0;i<=l/2;i++)
	{
		if(str[i]!=str[l-1-i])
		{
			flag=1;
			break;
		}
	}

	if(!flag)
		printf("Palindrome");
	else
		printf("Not Palindrome");

	getch();

}

