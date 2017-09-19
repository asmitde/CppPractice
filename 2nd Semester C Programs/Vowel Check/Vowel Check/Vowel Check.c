#include <stdio.h>
#include <conio.h>

void main()
{
	char ch;

	printf("Enter an alphabet: ");
	scanf("%c",&ch);

	switch(ch)
	{
	case 'A':
	case 'a':
	case 'E':
	case 'e':
	case 'I':
	case 'i':
	case 'O':
	case 'o':
	case 'U':
	case 'u':
		printf("\n%c is a vowel",ch);
		break;
	default:
		printf("\n%c is a not vowel",ch);
	}

	getch();
}

