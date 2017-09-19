#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;

template<class QT> class Queue
{
private:
	int maxQueueSize;
	bool IsFull();
	bool IsEmpty();

public:
	QT *_queue;
	int front, rear;

	Queue();
	void Clear();
	int Enqueue(QT &data);
	int Dequeue(QT &data);
	void Display() const;
};

template<class QT> Queue<QT>::Queue()
{
	system("cls");
	
	cout<<"Enter the maximum lenght of queue: ";
	cin>>maxQueueSize;

	_queue = new QT[maxQueueSize];
	front = rear = -1;
}

template<class QT> void Queue<QT>::Clear()
{
	fornt = -1;
	rear = -1;
}

template<class QT> bool Queue<QT>::IsFull()
{
	if((rear == maxQueueSize-1 && front == -1) || (front-rear == 1))
		return true;
	else
		return false;
}

template<class QT> bool Queue<QT>::IsEmpty()
{
	if(front == rear)
		return true;
	else
		return false;
}

template<class QT> int Queue<QT>::Enqueue(QT &data)
{
	if(IsFull())
	{
		cout<<"\aError: Queue is full...\nDo you want to overwrite the last entered element? (Y/N): ";
		char ch = getche();

		if(ch == 'Y' || ch == 'y')
		{
			_queue[rear] = data;
			return 0;
		}
		else
			return 1;
	}

	if(rear == maxQueueSize-1)
		rear = -1;

	_queue[++rear] = data;
	return 0;
}

template<class QT> int Queue<QT>::Dequeue(QT &data)
{
	if(IsEmpty())
	{
		cout<<"\aError: Queue is empty...";
		return 1;
	}

	if(front == maxQueueSize-1)
		front = -1;

	data = _queue[++front];
	return 0;
}

template<class QT> void Queue<QT>::Display() const
{
	if(IsFull())
	{
		cout<<"\aError: Queue is empty...";
		return;
	}

	cout<<"Queue:\nFront < ";
	int i = front+1;
	while(i < maxQueueSize)
	{
		cout<<_queue[i]<<" < ";
		if(i == rear)
		{
			cout<<"Rear";
			return;
		}
		else
			i++;
	}

	for(i = 0; i <= rear; i++)
		cout<<_queue[i]<<" < ";
	cout<<"Rear";
}	

template<class qQT, class dQT> void QueueOperations(qQT &queue, dQT &data)
{
	while(1)
	{
		system("cls");
		cout<<"Queue Operations\n";
		cout<<"\nKey \tFunction";
		cout<<"\n1 \tDisplay Queue";
		cout<<"\n2 \tEnqueue Data";
		cout<<"\n3 \tDequeue Data";
		cout<<"\n4 \tClear Queue";
		cout<<"\n\nR \tReturn to previous menu";
		cout<<"\n\nEnter choice...";
		
		dQT data;
		char ch = getch();
		switch(ch)
		{
		case '1':
			system("cls");

			

			cout<<"\n\nPress any key to return to menu...";
			getch();
			break;

		case '2':
			system("cls");

			cout<<"Enter data: ";
			cin>>data;
			if(!queue.Enqueue(data))
				cout<<"\nData queued successfully...";

			cout<<"\n\nPress any key to return to menu...";
			getch();
			break;

		case '3':
			system("cls");

			if(!queue.Dequeue(data))
				cout<<"\nData retrieved: "<<data;

			cout<<"\n\nPress any key to return to menu...";
			getch();
			break;

		case '4':
			system("cls");

			queue.Clear();
			cout<<"Queue cleared successfully...";

			cout<<"\n\nPress any key to return to menu...";
			getch();
			break;

		case 'R':
		case 'r':
			exit(0);

		default:
			system("cls");

			cout<<"\aError: Invalid Input...";

			cout<<"\n\nPress any key to return to menu...";
			getch();
		}
	}
}

void QueueTypeMenu()
{
	while(1)
	{
		system("cls");
		cout<<"Queue Type\n";
		cout<<"\nKey \tType";
		cout<<"\n1 \tInteger (int)";
		cout<<"\n2 \tLong Integer (long)";
		cout<<"\n3 \tFloating point (float)";
		cout<<"\n4 \tDouble (double)";
		cout<<"\n5 \tCharacter (char)";
		cout<<"\n\nR \tReturn to previous menu";
		cout<<"\n\nEnter your choice...";
		
		char ch = getch();
		switch(ch)
		{
		case '1':
			Queue<int> queue_int;
			int data_int;
			QueueOperations(queue_int, data_int);
			return;
			
		case '2':
			Queue<long> queue_long;
			long data_long;
			QueueOperations(queue_long, data_long);
			return;

		case '3':
			Queue<float> queue_float;
			float data_float;
			QueueOperations(queue_float, data_float);
			return;

		case '4':
			Queue<double> queue_double;
			double data_double;
			QueueOperations(queue_double, data_double);
			return;

		case '5':
			Queue<char> queue_char;
			char data_char;
			QueueOperations(queue_char, data_char);
			return;
			
		case 'R':
		case 'r':
			return;

		default:
			system("cls");

			cout<<"\aError: Invalid Input...";

			cout<<"\n\nPress any key to return to menu...";
			getch();
		}
	}
}

int main()
{
	while(1)
	{
		system("cls");
		cout<<"QUEUE\n";
		cout<<"\nKey \tFunction";
		cout<<"\nC \tChoose queue content type";
		cout<<"\nX \tExit";
		cout<<"\n\nEnter your choice...";

		char ch = getch();
		switch(ch)
		{
		case 'C':
		case 'c':
			QueueTypeMenu();
			break;
		case 'X':
		case 'x':
			exit(0);
		default:
			system("cls");

			cout<<"\aError: Invalid Input...";

			cout<<"\n\nPress any key to return to menu...";
			getch();
		}
	}	
}