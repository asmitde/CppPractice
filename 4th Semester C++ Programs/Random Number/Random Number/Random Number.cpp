// Random Number.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;


int main()
{
	int c;
	time_t *seed = new time_t;
	unsigned long random = time(seed);
	int l, h;
	cout<<"Enter a range to generate random numbers: ";
	cin>>l>>h;
	int a = h - l;

	while(1)
	{
		cout<<endl<<"Enter 1 to generate a random number, any other number to quit: ";
		cin>>c;
	
		if(c != 1)
			break;

		time(seed);
		
		random = *seed + random;

		float r = sin((double)random);
		
		r = abs(r) * a + l;

		cout<<r<<endl;
	}
	
	return 0;
}

