#include "queuelnk.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	Queue<int> queue;
	int data;
	char choice;

	while(1)
	{
		system("cls");
		cout<<"MENU"<<endl;
		cout<<"\nKey \tFunction"<<endl;
		cout<<"1 \tDisplay Queue"<<endl;
		cout<<"2 \tEnqueue Data"<<endl;
		cout<<"3 \tDequeue Data"<<endl;
		cout<<"4 \tDisplay Data at Front of Queue"<<endl;
		cout<<"5 \tDisplay Size of Queue"<<endl;
		cout<<"6 \tClear Queue"<<endl;
		cout<<"X \tExit"<<endl;
		cout<<"\nEnter choice: ";
		cin>>choice;

		try
		{
			switch(choice)
			{
			case '1':
				system("cls");

				cout<<"Queue contents:"<<endl;
				queue.display();

				cout<<endl;
				system("pause");
				break;

			case '2':
				system("cls");

				cout<<"Enter data: ";
				cin>>data;
				queue.enqueue(data);
				cout<<"\nData queued successfully...";

				cout<<endl;
				system("pause");
				break;

			case '3':
				system("cls");

				data = queue.dequeue();
				cout<<"Data dequeued: "<<data;

				cout<<endl;
				system("pause");
				break;

			case '4':
				system("cls");

				cout<<"Data at front of Queue: "<<queue.getFront();

				cout<<endl;
				system("pause");
				break;

			case '5':
				system("cls");

				cout<<"Size of Queue: "<<queue.getSize();

				cout<<endl;
				system("pause");
				break;

			case '6':
				system("cls");

				queue.clear();
				cout<<"Queue cleared successfully...";

				cout<<endl;
				system("pause");
				break;

			case 'X':
			case 'x':
				exit(0);

			default:
				system("cls");

				cout<<"\aError: Invalid Input...";

				cout<<endl;
				system("pause");
			}
		}
		catch (QueueException ex)
		{
			cout<<endl<<ex.error<<endl;
			system("pause");
		}
	}
}
