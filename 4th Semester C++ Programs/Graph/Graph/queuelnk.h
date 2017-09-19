#include <iostream>
#include <string>
using namespace std;

// Queue Exception class
// This class throws an exception in case of an overflow or underflow condition in queue.
class QueueException
{
public:
	enum errtype { __UNDERFLOW, __OVERFLOW };	// Error type ( Overflow / Underflow)

	string error;								// Contains the string form of the exception occurred.
	QueueException(errtype et)
	{
		if (et == __OVERFLOW)
			error = "\n\aError: Queue is full";
		else
			error = "\n\aError: Queue is empty";
	}
};


// Queue class
template <class QueueType> class Queue
{
protected:
	struct Node
	{
		QueueType data;
		float key;
		Node *link;
		Node(const QueueType &d = QueueType(), float p = 1, Node *l = NULL) : data(d), key(p), link(l) {};
	};

private:
	Node *front, *rear;							// Front & Rear pointers to queue
	int size;									// contains current size of queue
	
	bool isEmpty() const;						// Checks for empty queue

public:
	Queue();									// Constructor
	Queue(const Queue &cq);						// Copy Constructor
	~Queue();									// Destructor
	void enqueue(const QueueType &data);		// Enqueue data
	QueueType dequeue();						// Dequeue data
	QueueType getFront() const;					// returns element at front
	void display() const;						// Display queue
	int getSize() const;						// returns current queue size
	void clear();								// Clear queue
};

template <class QueueType> class PriorityQueue : public Queue<QueueType>
{
public:
	PriorityQueue() { };
	~PriorityQueue() { };

	void enqueue(const QueueType &data, float prty)
	{
		Node *node = new Node(data, prty);
		if(node == NULL)
			throw QueueException(QueueException::__OVERFLOW);
	
		if(front == NULL)
			front = rear = node;
		else
		{
			Node *temp = front, *tprev = NULL;
			while(temp->key < prty)
			{
				if(tprev != NULL)
					tprev = tprev->link;
				else
					tprev = temp;

				temp = temp->link;
			}

			node->link = temp;
			tprev->link = node;
			rear = node;
		}

		size++;
	}
};

template <class QueueType> Queue<QueueType>::Queue()
{
	front = rear = NULL;
	size = 0;
}

template <class QueueType> Queue<QueueType>::Queue(const Queue &cq)
{
	front = rear = NULL;
	Node *node = cq.front;
	
	while(node != NULL)
	{
		temp = new Node(node->data, NULL);
		if(front == NULL)
			front = temp;
		else
			rear->link = temp;

		rear = temp;
		node = node->link;
	}

	size = cq.size;
}

template <class QueueType> Queue<QueueType>::~Queue()
{
	Node *temp = NULL;	
	while(front != NULL)
	{
		temp = front;		
		front = front->link;
		delete temp;
	}
	rear = NULL;
}

template <class QueueType> bool Queue<QueueType>::isEmpty() const
{
	if(front == NULL)
		return true;
	else
		return false;
}

template <class QueueType> void Queue<QueueType>::enqueue(const QueueType &data)
{
	Node *node = new Node(data);
	if(node == NULL)
		throw QueueException(QueueException::__OVERFLOW);
	
	if(front == NULL)
		front = rear = node;
	else
	{
		rear->link = node;
		rear = node;
	}

	size++;
}

template <class QueueType> QueueType Queue<QueueType>::dequeue()
{
	if(isEmpty())
		throw QueueException(QueueException::__UNDERFLOW);

	Node *temp = front;
	QueueType td = front->data;
	front = front->link;
	delete temp;
	size--;
	if(size == 0)
		rear = NULL;
	return td;
}

template <class QueueType> QueueType Queue<QueueType>::getFront() const
{
	if(isEmpty())
		throw QueueException(QueueException::__UNDERFLOW);
	
	return front->data;
}

template <class QueueType> void Queue<QueueType>::display() const
{
	if(isEmpty())
		throw QueueException(QueueException::__UNDERFLOW);
	
	Node *node = front;
	while(node != NULL)
	{
		cout<<node->data<<endl;
		node = node->link;
	}
}

template <class QueueType> int Queue<QueueType>::getSize() const
{
	return size;
}

template <class QueueType> void Queue<QueueType>::clear()
{
	Node *temp = NULL;	
	while(front != NULL)
	{
		temp = front;		
		front = front->link;
		delete temp;
	}
	rear = NULL;
}