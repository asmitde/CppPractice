#include <stdio.h>
#include <conio.h>

void main()
{
	int year;

	printf("Enter year: ");
	scanf("%d",&year);

	if((year%100!=0 && year%4==0) || year%400==0)
		printf("\n%d is a leap year",year);
	else
		printf("\n%d is a not leap year",year);

	getch();
}

