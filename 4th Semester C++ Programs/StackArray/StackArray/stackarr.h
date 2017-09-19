#include <string>
using namespace std;

// Stack Exception class
// This class throws an exception in case of an overflow or underflow condition in stack.
class StackException
{
public:
	enum errtype { __UNDERFLOW, __OVERFLOW };		// Error type ( Overflow / Underflow)
	string error;									// Contains the string form of the exception occurred.
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
private:
	StackType *_stack;
	int capacity;
	int stacktop;

	bool isFull() const;
	bool isEmpty() const;

public:
	Stack(int c);
	Stack(const Stack &cstck);
	~Stack();
	void push(const StackType &data);
	StackType pop();
	StackType top() const;
	void display() const;
	int getSize() const;
	int getCapacity() const;
};

template <class StackType> Stack<StackType>::Stack(int c = 10)
{
	capacity = c;
	_stack = new StackType[capacity];
	stacktop = -1;
}

template <class StackType> Stack<StackType>::Stack(const Stack &cstck)
{
	capacity = cstck.capacity;
	stacktop = cstck.stacktop;
	_stack = new StackType[capacity];

	for(int i = 0; i <= stacktop; i++)
		_stack[i] = cstck._stack[i];
}

template <class StackType> Stack<StackType>::~Stack()
{
	delete []_stack;
}

template <class StackType> bool Stack<StackType>::isFull() const
{
	if(stacktop == capacity - 1)
		return true;
	else
		return false;
}

template <class StackType> bool Stack<StackType>::isEmpty() const
{
	if(stacktop == -1)
		return true;
	else
		return false;
}

template <class StackType> void Stack<StackType>::push(const StackType &data)
{
	if(isFull())
		throw StackException(StackException::__OVERFLOW);
	_stack[++stacktop] = data;
}

template <class StackType> StackType Stack<StackType>::pop()
{
	if(isEmpty())
		throw StackException(StackException::__UNDERFLOW);
	return _stack[stacktop--];
}

template <class StackType> StackType Stack<StackType>::top() const
{
	if(isEmpty())
		throw StackException(StackException::__UNDERFLOW);
	return _stack[stacktop];
}

template <class StackType> void Stack<StackType>::display() const
{
	if(isEmpty())
		throw StackException(StackException::__UNDERFLOW);
	
	cout<<"Stack Contents:\n";
	for(int i = 0; i <= stacktop; i++)
		cout<<_stack[i]<<endl;
}

template <class StackType> int Stack<StackType>::getSize() const
{
	return stacktop + 1;
}

template <class StackType> int Stack<StackType>::getCapacity() const
{
	return capacity;
}