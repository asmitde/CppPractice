#include <iostream>
#include <string>
using namespace std;

// Stack Exception class
// This class throws an exception in case of an overflow or underflow condition in stack.
class StackException
{
public:
	enum errtype { __UNDERFLOW, __OVERFLOW };	// Error type ( Overflow / Underflow)

	string error;								// Contains the string form of the exception occurred.
	StackException(errtype et)
	{
		if (et == __OVERFLOW)
			error = "\n\aError: Stack Overflow";
		else
			error = "\n\aError: Stack Underflow";
	}
};


// Stack class
template <class StackType> class Stack
{
protected:
	struct Node
	{
		StackType data;
		Node *link;
		Node(const StackType &d = StackType(), Node *l = NULL) : data(d), link(l) {};
	};

private:
	Node *stacktop;
	int size;
	
	bool isEmpty() const;

public:
	Stack();
	Stack(const Stack &cstck);
	~Stack();
	void push(const StackType &data);
	StackType pop();
	StackType top() const;
	void display() const;
	int getSize() const;
	void clear();
};

template <class StackType> Stack<StackType>::Stack()
{
	stacktop = NULL;
	size = 0;
}

template <class StackType> Stack<StackType>::Stack(const Stack &cstck)
{
	stacktop = NULL;
	Node *node = cstck.stacktop;
	Node *prev = NULL;
	
	while(node != NULL)
	{
		Node *temp = new Node(node->data, NULL);
		if(stacktop == NULL)
			stacktop = temp;
		else
			prev->link = temp;

		prev = temp;
		node = node->link;
	}

	size = cstck.size;
}

template <class StackType> Stack<StackType>::~Stack()
{
	Node *temp = NULL;	
	while(stacktop != NULL)
	{
		temp = stacktop;		
		stacktop = stacktop->link;
		delete temp;
	}
}

template <class StackType> bool Stack<StackType>::isEmpty() const
{
	if(stacktop == NULL)
		return true;
	else
		return false;
}

template <class StackType> void Stack<StackType>::push(const StackType &data)
{
	Node *node = new Node(data, stacktop);
	if(node == NULL)
		throw StackException(StackException::__OVERFLOW);
	
	stacktop = node;
	size++;
}

template <class StackType> StackType Stack<StackType>::pop()
{
	if(isEmpty())
		throw StackException(StackException::__UNDERFLOW);

	Node *temp = stacktop;
	StackType td = stacktop->data;
	stacktop = stacktop->link;
	delete temp;
	size--;
	return td;
}

template <class StackType> StackType Stack<StackType>::top() const
{
	if(isEmpty())
		throw StackException(StackException::__UNDERFLOW);
	
	return stacktop->data;
}

template <class StackType> void Stack<StackType>::display() const
{
	if(isEmpty())
		throw StackException(StackException::__UNDERFLOW);
	
	Node *node = stacktop;
	while(node != NULL)
	{
		cout<<node->data<<endl;
		node = node->link;
	}
}

template <class StackType> int Stack<StackType>::getSize() const
{
	return size;
}

template <class StackType> void Stack<StackType>::clear()
{
	Node *temp = NULL;	
	while(stacktop != NULL)
	{
		temp = stacktop;		
		stacktop = stacktop->link;
		delete temp;
	}
}