#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;

template <class T> class Node
{
public:
	T data;
	Node<T> *link;

	Node(T x, Node *p = NULL)
	{
		data = x;
		link = p;
	}
};

template <class T> class Stack
{
public:
	Node<T> *top;
	
	Stack()
	{
		top = NULL;
	}

	void IsEmpty()
	{
		if(top == NULL)
			throw true;
	}

	void push(T data);
	T pop();
};

template <class T> void Stack<T>::push(T data)
{
	Node<T> *_node = NULL;

	try
	{
		_node = new Node<T>(data, top);
	}
	catch(bad_alloc xa)
	{
		cout<<"\a\nError: Stack is full...";
		exit(1);
	}

	top = _node;
}

template <class T> T Stack<T>::pop()
{
	try
	{
		IsEmpty();
	}
	catch(bool err)
	{
		cout<<"\a\nError: Stack is empty...";
		exit(1);
	}

	Node<T> *_node = top;
	T _data = _node->data;
	delete _node;
	return _data;
}

int main()
{
}