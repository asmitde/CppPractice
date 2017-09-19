// Uppercase.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <ctype.h>
#include <conio.h>

void main()
{
	char text[80], c; int i=0;

	while((c=getchar())!='\n')
		text[i++]=toupper(c);

	text[i]='\0';
	i=0;

	while((c=text[i++])!='\0')
		putchar(c);

	getch();
}

