// StackArray.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdlib>
#include "stackarr.h"
using namespace std;



int main()
{
	Stack<int> stck(3);

	stck.push(1);
	cout<<stck.pop()<<endl;
	try {
		cout<<stck.pop()<<endl;
	} catch (StackException e) {
		cout<<e.error<<endl;
	}
	stck.push(1);
	stck.push(2);
	stck.push(3);
	stck.display();
	cout<<stck.top()<<endl;
	try {
		stck.push(4);
	} catch (StackException e) {
		cout<<e.error<<endl;
	}
	Stack<int> stck2(stck);
	stck2.display();
	cout<<stck2.getSize();
	Stack<int> stck3 = stck2;
	cout<<stck3.pop();
	stck2.display();

	return 0;
}
