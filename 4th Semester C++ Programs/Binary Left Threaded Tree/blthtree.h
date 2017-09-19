#ifndef BLTHTREE_H_
#define BLTHTREE_H_
#include "stacklnk.h"

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

template <class T> class BinaryLeftThreadedTree
{
private:
	ThNode<T> *root;
	int size;

	void display(ThNode<T> *node, int level);
	void padding(char c, int level);

public:
	BinaryLeftThreadedTree();

	void displayTree();
	void inOrder();

	void insertElement(T dat);
};

template <class T> BinaryLeftThreadedTree<T>::BinaryLeftThreadedTree()
{
	root = NULL;
	size = 0;
}

template <class T> void BinaryLeftThreadedTree<T>::insertElement(T dat)
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
		if(dat >= node->data)
		{
			node = node->rightChild;
		}
		else if(node->isThreadLink == false)
		{
			node = node->leftChild;
		}
		else
			break;
	}

	if(dat >= prevNode->data)
	{
		prevNode->rightChild = newNode;
		newNode->leftChild = prevNode;
		newNode->isThreadLink = true;
	}
	else if(dat < prevNode->data)
	{
		newNode->leftChild = prevNode->leftChild;
		newNode->isThreadLink = true;
		prevNode->leftChild = newNode;
		prevNode->isThreadLink = false;
	}
}

template <class T> void BinaryLeftThreadedTree<T>::inOrder()
{
	ThNode<T> *node = root, *prevNode;
	Stack<T> stck;

	while(node != NULL && node->rightChild != NULL)
		node = node->rightChild;

	while(node != NULL)
	{
		stck.push(node->data);

	    prevNode = node;
	    node = node->leftChild;

		if(prevNode->isThreadLink == false && node != NULL)
		{
			while(node->rightChild != NULL)
				node = node->rightChild;
		}
	}

	while(stck.getSize())
		cout<<stck.pop()<<" ";
}

template <class T> void BinaryLeftThreadedTree<T>::displayTree()
{
	display(root, 0);
}

template <class T> void BinaryLeftThreadedTree<T>::padding(char c, int n)
{
	for(int i = 0; i < n; i++)
		std::cout<<c;
}

template <class T> void BinaryLeftThreadedTree<T>::display(ThNode<T> *node, int level)
{
	if(node == NULL)
	{
		padding('\t', level);
		std::cout<<'~'<<std::endl;
		return;
	}

	display(node->rightChild, level+1);

	padding('\t', level);
	std::cout<<node->data<<endl;

	if(node->isThreadLink == false)
		display(node->leftChild, level+1);
	else
	{
		padding('\t', level+1);
		std::cout<<'~'<<std::endl;
	}
}

#endif /* BLTHTREE_H_ */
