// Reverse_strings_in_array.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <conio.h>
#include <string.h>

void xstrrev(char *p)
{
////////////////////////////////////////
// This part works in Turbo C compiler
/*
	int l,i; char t,*tt;
	l=strlen(p);
	tt=p+l-1;
	for(i=1;i<=l/2;i++)
	{
		t=*p;
 		*p=*tt;
		*tt=t;
		p++;
		tt--;
	}
*/
}

void main()
{
	int i; char str[80];
	char *s[]={"To err is human","But to really mess things up","One needs to know C"};

	for(i=0;i<=2;i++)
	{
		
/////////////////////////////////////////
// For Turbo C Compiler only
//		xstrrev(s[i]);
/////////////////////////////////////////
		strcpy(str,s[i]);
		strrev(str);
		printf("%s\n",str);
	}

	getch();
}

