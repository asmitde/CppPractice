#include <iostream>
#include "heap.h"
using namespace std;

int main()
{
	Heap<int> hp(50);
	int data;
	char choice;

	while(1)
	{
		system("cls");
		cout<<"MENU"<<endl;
		cout<<"\nKey \tFunction"<<endl;
		cout<<"1 \tDisplay Heap (BFS Traversal)"<<endl;
		cout<<"2 \tInsert Data"<<endl;
		cout<<"3 \tRemove Data"<<endl;
		cout<<"X \tExit"<<endl;
		cout<<"\nEnter choice: ";
		cin>>choice;

		try
		{
			switch(choice)
			{
			case '1':
				system("cls");

				cout<<"Heap contents:"<<endl;
				hp.bfsTraversal();

				cout<<endl;
				system("pause");
				break;

			case '2':
				system("cls");

				cout<<"Enter data: ";
				cin>>data;
				hp.insert(data);
				cout<<"\nData inserted successfully...";

				cout<<endl;
				system("pause");
				break;

			case '3':
				system("cls");

				data = hp.remove();
				cout<<"Data removed: "<<data;

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
		catch (HeapException ex)
		{
			cout<<endl<<ex.error<<endl;
			system("pause");
		}
	}
	return 0;
}

