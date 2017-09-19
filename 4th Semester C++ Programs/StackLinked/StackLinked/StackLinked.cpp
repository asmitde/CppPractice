// StackLinked.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include "stacklnk.h"
using namespace std;

int main()
{
	Stack<int> stack;
	int data;
	char choice;

	while(1)
	{
		system("cls");
		cout<<"MENU"<<endl;
		cout<<"\nKey \tFunction"<<endl;
		cout<<"1 \tDisplay Stack"<<endl;
		cout<<"2 \tPush Data"<<endl;
		cout<<"3 \tPop Data"<<endl;
		cout<<"4 \tDisplay Data at Top of Stack"<<endl;
		cout<<"5 \tDisplay Size of Stack"<<endl;
		cout<<"6 \tClear Stack"<<endl;
		cout<<"X \tExit"<<endl;
		cout<<"\nEnter choice: ";
		cin>>choice;

		try
		{
			switch(choice)
			{
			case '1':
				system("cls");

				cout<<"Stack contents:"<<endl;
				stack.display();

				cout<<endl;
				system("pause");
				break;

			case '2':
				system("cls");

				cout<<"Enter data: ";
				cin>>data;
				stack.push(data);
				cout<<"\nData pushed successfully...";

				cout<<endl;
				system("pause");
				break;

			case '3':
				system("cls");

				data = stack.pop();
				cout<<"Data popped: "<<data;

				cout<<endl;
				system("pause");
				break;

			case '4':
				system("cls");

				cout<<"Data at front of Stack: "<<stack.top();

				cout<<endl;
				system("pause");
				break;

			case '5':
				system("cls");

				cout<<"Size of Stack: "<<stack.getSize();

				cout<<endl;
				system("pause");
				break;

			case '6':
				system("cls");

				stack.clear();
				cout<<"Stack cleared successfully...";

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
		catch (StackException ex)
		{
			cout<<endl<<ex.error<<endl;
			system("pause");
		}
	}
}
