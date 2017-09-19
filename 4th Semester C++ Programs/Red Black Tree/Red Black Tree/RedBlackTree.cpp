#include <iostream>
#include "rbtree.h"
using namespace std;

int main()
{
	RBTree <int> r1;
	r1.insert(7);
	r1.insert(1);
	r1.insert(100);
	r1.insert(29);
	r1.insert(78);
	r1.insert(777);
	r1.displayTree();

	return 0;
}