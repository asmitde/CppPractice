#include <iostream>
#include <conio.h>

using namespace std;

long sq(long n)
{
	return n;
}

double sq(double n)
{
	return n;
}

int main(void)
{
	cout<<sq(10.5);

	getch();
	return 0;
}