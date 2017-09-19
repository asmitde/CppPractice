// BinarySearchTree.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

struct Node;
template <class BSTType> class BinarySearchTree
{
protected:
	struct Node
	{
		BSTType data;
		Node *leftChild, *rightChild;
		Node(const BSTType &d = BSTType(), Node *lc = NULL, Node *rc = NULL) : data(d), leftChild(lc), rightChild(rc) {};
	};

private:
	Node *root;
	int size;

public:
	BinarySearchTree();
	BinarySearchTree(BSTType d);
	BinarySearchTree(const BinarySearchTree &cbst);
	~BinarySearchTree();

	void preOrder();
	void inOrder();
	void postOrder();

	Node* insertElement(BSTType d)
	{
	if(root == NULL)
	{
		root = new Node(d, NULL, NULL);
		size++;
		return root;
	}

	BinarySearchTree leftSubTree, rightSubTree;

	if(d <= root->data)
	{
		leftSubTree.root = root->leftChild;
		root->leftChild = leftSubTree.insertElement(d);
	}
	else
	{
		rightSubTree.root = root->rightChild;
		root->rightChild = rightSubTree.insertElement(d);
	}

	size++;
	return root;	
	}
	void deleteElement(BSTType d);

	bool isElementPresent(BSTType d);

	int sizeOfTree();
	int maxHeight();
	int minHeight();
	int maxPathWeight();
	int minPathWeight();
};

template <class BSTType> BinarySearchTree<BSTType>::BinarySearchTree()
{
	root = NULL;
	size = 0;
}

template <class BSTType> BinarySearchTree<BSTType>::BinarySearchTree(BSTType d)
{
	root = new Node(d, NULL, NULL);
	size = 1;
}

template<class BSTType> BinarySearchTree<BSTType>::~BinarySearchTree()
{
};

template <class BSTType> void BinarySearchTree<BSTType>::preOrder()
{
	if(root == NULL)
		return;

	cout<<root->data<<" ";

	BinarySearchTree leftSubTree, rightSubTree;

	leftSubTree.root = root->leftChild;
	leftSubTree.preOrder();

	rightSubTree.root = root->rightChild;
	rightSubTree.preOrder();
}

template <class BSTType> void BinarySearchTree<BSTType>::inOrder()
{
	if(root == NULL)
		return;

	BinarySearchTree<int> leftSubTree, rightSubTree;

	leftSubTree.root = root->leftChild;
	leftSubTree.inOrder();

	cout<<root->data<<" ";

	rightSubTree.root = root->rightChild;
	rightSubTree.inOrder();
}

template <class BSTType> void BinarySearchTree<BSTType>::postOrder()
{
	if(root == NULL)
		return;

	BinarySearchTree leftSubTree, rightSubTree;

	leftSubTree.root = root->leftChild;
	leftSubTree.postOrder();

	rightSubTree.root = root->rightChild;
	rightSubTree.postOrder();

	cout<<root->data<<" ";
}

/*
template <class BSTType> Node* BinarySearchTree<BSTType>::insertElement(BSTType d)
{
	if(root == NULL)
	{
		root = new Node(d, NULL, NULL);
		size++;
		return root;
	}

	BinarySearchTree leftSubTree, rightSubTree;

	if(d <= root->data)
	{
		leftSubTree.root = root->leftChild;
		root->leftChild = leftSubTree.insertElement(d);
	}
	else
	{
		rightSubTree.root = root->rightChild;
		root->rightChild = rightSubTree.insertElement(d);
	}

	size++;
	return root;
}
*/

template <class BSTType> int BinarySearchTree<BSTType>::sizeOfTree()
{
	return size;
}

template <class BSTType> int BinarySearchTree<BSTType>::maxHeight()
{
	int lSz, rSz;
	BinarySearchTree leftSubTree, rightSubTree;

	if(root == NULL)
		return 0;

	leftSubTree.root = root->leftChild;
	lSz = leftSubTree.maxHeight();
	rightSubTree.root = root->rightChild;
	rSz = rightSubTree.maxHeight();

	return (lSz > rSz ? lSz : rSz) + 1;
}

template <class BSTType> int BinarySearchTree<BSTType>::minHeight()
{
	int lSz, rSz;
	BinarySearchTree leftSubTree, rightSubTree;

	if(root == NULL)
		return 0;

	leftSubTree.root = root->leftChild;
	lSz = leftSubTree.minHeight();
	rightSubTree.root = root->rightChild;
	rSz = rightSubTree.minHeight();

	return (lSz < rSz ? lSz : rSz) + 1;
}

template <class BSTType> int BinarySearchTree<BSTType>::maxPathWeight()
{
	int lWt, rWt;
	BinarySearchTree leftSubTree, rightSubTree;

	if(root == NULL)
		return 0;

	leftSubTree.root = root->leftChild;
	lWt = leftSubTree.maxPathWeight();
	rightSubTree.root = root->rightChild;
	rWt = rightSubTree.maxPathWeight();

	return (lWt > rWt ? lWt : rWt) + root->data;
}

template <class BSTType> int BinarySearchTree<BSTType>::minPathWeight()
{
	int lWt, rWt;
	BinarySearchTree leftSubTree, rightSubTree;

	if(root == NULL)
		return 0;

	leftSubTree.root = root->leftChild;
	lWt = leftSubTree.minPathWeight();
	rightSubTree.root = root->rightChild;
	rWt = rightSubTree.minPathWeight();

	return (lWt < rWt ? lWt : rWt) + root->data;
}

template <class BSTType> bool BinarySearchTree<BSTType>::isElementPresent(BSTType d)
{
	if(root == NULL)
		return false;

	BinarySearchTree leftSubTree, rightSubTree;

	if(d < root->data)
	{
		leftSubTree.root = root->leftChild;
		return leftSubTree.isElementPresent(d);
	}
	else if(d > root->data)
	{
		rightSubTree.root = root->rightChild;
		return rightSubTree.isElementPresent(d);
	}
	else
		return true;
}
int main()
{
	BinarySearchTree<int> bst;
	int n;
	cout<<"Enter no of values";
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cout<<"Enter element: ";
		int data;
		cin>>data;
		bst.insertElement(data);
	}
/*	bst.insertElement(50);
	bst.insertElement(25);
	bst.insertElement(75);
	bst.insertElement(10);
	bst.insertElement(40);
	bst.insertElement(60);
	bst.insertElement(90);
	bst.insertElement(5);
	bst.insertElement(20);
	bst.insertElement(30);
	bst.insertElement(55);
	bst.insertElement(70);
	*/
	
	cout<<"\nPre order:";
	bst.preOrder();
	cout<<endl;
	cout<<"\nIn order:";
	bst.inOrder();
	cout<<endl;
	cout<<"\nPost order:";
	bst.postOrder();

	cout<<endl<<"Max Height = "<<bst.maxHeight()<<endl<<"Min Height = "<<bst.minHeight();
	cout<<endl<<"Max Path weight = "<<bst.maxPathWeight()<<endl<<"Min path weight = "<<bst.minPathWeight();
/*	if(bst.isElementPresent(70)) cout<<"\n70 present";
	else cout<<"\n70 absent";
	if(bst.isElementPresent(100)) cout<<"\n100 present";
	else cout<<"\n100 absent";*/
	return 0;
}

