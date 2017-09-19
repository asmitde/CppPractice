#include <iostream>
#include "brthtree.h"
using namespace std;

int main()
{
	BinaryThreadedTree<int> thtree;
	int data;
	char choice;

	while(1)
	{
		system("cls");
		cout<<"MENU"<<endl;
		cout<<"\nKey \tFunction"<<endl;
		cout<<"1 \tDisplay Tree"<<endl;
		cout<<"2 \tInsert Data"<<endl;
		cout<<"3 \tDisplay PreOrder traversal"<<endl;
		cout<<"4 \tDisplay InOrder traversal"<<endl;
		cout<<"X \tExit"<<endl;
		cout<<"\nEnter choice: ";
		cin>>choice;

		switch(choice)
		{
		case '1':
			system("cls");

			cout<<"Tree:"<<endl;
			thtree.displayTree();

			cout<<endl;
			system("pause");
			break;

		case '2':
			system("cls");

			cout<<"Enter data: ";
			cin>>data;
			thtree.insertElement(data);
			cout<<"\nData inserted successfully...";
			
			cout<<endl;
			system("pause");
			break;

		case '3':
			system("cls");

			cout<<"\nPreOrder traversal:"<<endl;
			thtree.preOrder();

			cout<<endl;
			system("pause");
			break;

		case '4':
			system("cls");

			cout<<"\nInOrder traversal:"<<endl;
			thtree.inOrder();

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
			break;
		}
	}
}