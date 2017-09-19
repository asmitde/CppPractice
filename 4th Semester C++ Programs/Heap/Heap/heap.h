#include <string>

class HeapException
{
	public:
	enum errtype { __UNDERFLOW, __OVERFLOW };		// Error type ( Overflow / Underflow)
	std::string error;									// Contains the string form of the exception occurred.
	HeapException(errtype et)
	{
		if (et == __OVERFLOW)
			error = "\n\aError: Heap Overflow";
		else
			error = "\n\aError: Heap Underflow";
	}
};

template <class H> class Heap
{
private:
	H *_array;
	int capacity;
	int size;

public:
	Heap(int n);

	void insert(H data);
	H remove();
	void bfsTraversal();
};

template <class H> Heap<H>::Heap(int n)
{
	capacity = n;
	_array = new H[capacity];
	size = 0;
}

template <class H> void Heap<H>::insert(H data)
{
	if(size == capacity)
		throw HeapException(HeapException::__OVERFLOW);
	
	_array[size] = data;
	int pos = size;
	size++;

	while(pos > 0)
	{
		if(_array[(pos - 1) / 2] >= data)
			break;
		else
		{
			swap(_array[(pos - 1) / 2], _array[pos]);
			pos = (pos - 1) / 2;
		}
	}
}

template <class H> H Heap<H>::remove()
{
	if(size == 0)
		throw HeapException(HeapException::__UNDERFLOW);
	
	H data = _array[0];
	_array[0] = _array[size - 1];

	size--;
	int pos = 0;

	while(pos < size - 2)
	{
		if(_array[pos] >= _array[2 * pos + 1] && _array[pos] >= _array[2 * pos + 2])
			break;
		else if(_array[pos] >= _array[2 * pos + 1] && _array[pos] < _array[2 * pos + 2])
		{
			swap(_array[pos], _array[2 * pos + 2]);
			pos = 2 * pos + 2;
		}
		else if(_array[pos] < _array[2 * pos + 1] && _array[pos] >= _array[2 * pos + 2])
		{
			swap(_array[pos], _array[2 * pos + 1]);
			pos = 2 * pos + 1;
		}
		else
		{
			int i = 2 * pos + 1;
			int j = 2 * pos + 2;

			if(_array[i] > _array[j])
			{
				swap(_array[pos], _array[i]);
				pos = i;
			}
			else
			{
				swap(_array[pos], _array[j]);
				pos = j;
			}
		}
	}

	return data;
}

template <class H> void Heap<H>::bfsTraversal()
{
	if(size == 0)
		throw HeapException(HeapException::__UNDERFLOW);
	
	for(int i = 0; i < size; i++)
		cout<<_array[i]<<" ";
}