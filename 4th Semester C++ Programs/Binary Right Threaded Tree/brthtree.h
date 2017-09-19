#ifndef BRTHTREE_H_
#define BRTHTREE_H_

#include <iostream>
using namespace std;

template <class T> class ThNode
{
public:
	T data;
	ThNode *leftChild, *rightChild;
	bool isThreadLink;
	ThNode(const T &d, ThNode *lc = NULL, ThNode *rc = NULL, bool tl = false)
	{
		data = d;
		leftChild = lc;
		rightChild = rc;
		isThreadLink = tl;
	}
};

template <class T> class BinaryThreadedTree
{
private:
	ThNode<T> *root;
	int size;

	void display(ThNode<T> *node, int level);
	void padding(char c, int level);

public:
	BinaryThreadedTree();

	void displayTree();

	void preOrder();
	void inOrder();

	void insertElement(T dat);
};

template <class T> BinaryThreadedTree<T>::BinaryThreadedTree()
{
	root = NULL;
	size = 0;
}

template <class T> void BinaryThreadedTree<T>::insertElement(T dat)
{
	ThNode<T> *newNode = new ThNode<T>(dat);

	if(root == NULL)
	{
		root = newNode;
		size++;
		return;
	}

	ThNode<T> *node = root, *prevNode;

	while(node != NULL)
	{
		prevNode = node;
		if(dat < node->data)
		{
			node = node->leftChild;
		}
		else if(node->isThreadLink == false)
		{
			node = node->rightChild;
		}
		else
			break;
	}

	if(dat < prevNode->data)
	{
		prevNode->leftChild = newNode;
		newNode->rightChild = prevNode;
		newNode->isThreadLink = true;
	}
	else if(dat >= prevNode->data)
	{
		newNode->rightChild = prevNode->rightChild;
		newNode->isThreadLink = true;
		prevNode->rightChild = newNode;
		prevNode->isThreadLink = false;
	}
}

template <class T> void BinaryThreadedTree<T>::preOrder()
{
	ThNode<T> *node = root;

	while(node != NULL)
	{
	    cout<<node->data<<" ";

		if(node->leftChild != NULL)
			node = node->leftChild;
		else
		{
			while(node->isThreadLink == true)
				node = node->rightChild;

			node = node->rightChild;
		}
	}
}

template <class T> void BinaryThreadedTree<T>::inOrder()
{
	ThNode<T> *node = root, *prevNode;

	while(node != NULL && node->leftChild != NULL)
		node = node->leftChild;

	while(node != NULL)
	{
	    cout<<node->data<<" ";

	    prevNode = node;
	    node = node->rightChild;

		if(prevNode->isThreadLink == false && node != NULL)
		{
			while(node->leftChild != NULL)
				node = node->leftChild;
		}
	}
}

template <class T> void BinaryThreadedTree<T>::displayTree()
{
	display(root, 0);
}

template <class T> void BinaryThreadedTree<T>::padding(char c, int n)
{
	for(int i = 0; i < n; i++)
		std::cout<<c;
}

template <class T> void BinaryThreadedTree<T>::display(ThNode<T> *node, int level)
{
	if(node == NULL)
	{
		padding('\t', level);
		std::cout<<'~'<<std::endl;
		return;
	}

	if(node->isThreadLink == false)
		display(node->rightChild, level+1);
	else
	{
		padding('\t', level+1);
		std::cout<<'~'<<std::endl;
	}

	padding('\t', level);
	std::cout<<node->data<<endl;
	display(node->leftChild, level+1);
}

#endif /* BRTHTREE_H_ */
