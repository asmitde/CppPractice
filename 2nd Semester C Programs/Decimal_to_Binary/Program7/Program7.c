
#include <stdio.h>
#include <conio.h>
#include <math.h>

long decimal_to_binary(int dec)
{
	int p=0,r; long bin=0;

	while(dec)
	{
		r=dec%2;
		dec/=2;
		bin=bin+r*pow(10.0,p++);
	}

	return bin;
}

void main()
{
	int dec; long bin;

	printf("Enter a decimal number: ");
	scanf("%d",&dec);

	bin=decimal_to_binary(dec);

	printf("\nDecimal(%d) = Binary(%ld)",dec,bin);

	getch();
}

