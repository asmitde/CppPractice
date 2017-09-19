
#include <iostream>
#include "avltree.h"
#include <string>
using namespace std;

int main()
{
	AVLTree<int> avl;
	int data;
	char choice;

/* TEST DATA-----------------
	avl.insertElement("mar");
	avl.insertElement("nov");
	avl.insertElement("aug");
	avl.insertElement("apr");
	avl.insertElement("jan");
	avl.insertElement("dec");
	avl.insertElement("jul");
	avl.insertElement("feb");
	avl.insertElement("jun");
	avl.insertElement("oct");
	avl.insertElement("sep");
	avl.displayTree();
*/

	while(1)
	{
		system("cls");
		cout<<"MENU"<<endl;
		cout<<"\nKey \tFunction"<<endl;
		cout<<"1 \tDisplay AVL Tree"<<endl;
		cout<<"2 \tInsert Data"<<endl;
		cout<<"3 \tDisplay InOrder Traversal"<<endl;
		cout<<"X \tExit"<<endl;
		cout<<"\nEnter choice: ";
		cin>>choice;

		switch(choice)
		{
		case '1':
			system("cls");

			cout<<"AVL Tree contents:"<<endl;
			avl.displayTree();

			cout<<endl;
			system("pause");
			break;

		case '2':
			system("cls");

			cout<<"Enter data to insert: ";
			cin>>data;
			avl.insertElement(data);
			cout<<"\nData inserted successfully...";

			cout<<endl;
			system("pause");
			break;

		case '3':
			system("cls");

			cout<<endl<<"Inorder traversal (<heightLeft> <data> <heightRight>):"<<endl;
			avl.inOrder();

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
}

