// String reverse _recursive.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <conio.h>

char str[80];

void astrrev()
{
	char c; static int i=0;
	c=str[i++];
	if(c=='\0') return;

	astrrev();
	putchar(c);
}

void pstrrev(char *p)
{
	if(*p=='\0') return;

	pstrrev(++p);
	putchar(*--p);
}

void main()
{
	printf("Enter a string: "); gets(str);

	printf("\nReversed string: \n");

	astrrev();
	printf("\n");
	pstrrev(str);

	getch();
}