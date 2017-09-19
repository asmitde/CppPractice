
#include <stdio.h>
#include <conio.h>

char hex[10];

void decimal_to_hexadecimal(int dec)
{
	int p=0,r,i; char t;

	while(dec)
	{
		r=dec%16;
		dec/=16;
		
		if(r<=9)
			hex[p++]=r+48;
		else
			hex[p++]=r+55;
	}

	for(i=0;i<=(p-1)/2;i++)
	{
		t=hex[i];
		hex[i]=hex[p-1-i];
		hex[p-1-i]=t;
	}
}

void main()
{
	int dec;

	printf("Enter a decimal number: ");
	scanf("%d",&dec);

	decimal_to_hexadecimal(dec);

	printf("\nDecimal(%d) = Hexadecimal(%s)",dec,hex);

	getch();
}

