// Successive vowels.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <conio.h>

void main()
{
	char str[80]; int i=1,c=0;
	printf("Enter a string: ");
	gets(str);

	while(str[i]!='\0')
	{
		if((str[i]=='A' || str[i]=='a' || str[i]=='E' || str[i]=='e' ||
			str[i]=='I' || str[i]=='i' || str[i]=='O' || str[i]=='o' ||
			str[i]=='U' || str[i]=='u') && (str[i+1]=='A' || str[i+1]=='a' ||
			str[i+1]=='E' || str[i+1]=='e' || str[i+1]=='I' || str[i+1]=='i' ||
			str[i+1]=='O' || str[i+1]=='o' || str[i+1]=='U' || str[i+1]=='u'))

			c++;
		i++;
	}

	printf("\nNo of occurences of two successive vowels: %d",c);

	getch();
}

