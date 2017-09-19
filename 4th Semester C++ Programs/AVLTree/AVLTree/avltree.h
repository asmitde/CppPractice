
template <class T> class AVLNode
{
public:	
	T data;
	int heightLeft, heightRight;
	AVLNode *leftChild, *rightChild;

	AVLNode(T dat, int hl = 0, int hr = 0, AVLNode *lc = NULL, AVLNode *rc = NULL)
	{
		data = dat;
		heightLeft = hl;
		heightRight = hr;
		leftChild = lc;
		rightChild = rc;
	}
};

template <class T> class AVLTree
{
private:
	AVLNode<T> *root;
	int size;

	AVLNode<T>* insertElementHelper(T dat, AVLNode<T> *node);

	void padding(char c, int n);
	void display(AVLNode<T> *node, int level);
	void inOrderHelper(AVLNode<T> *node);

	AVLNode<T>* adjustHeight(AVLNode<T> *node, T dat);
	AVLNode<T>* rotateLL(AVLNode<T> *node);
	AVLNode<T>* rotateRR(AVLNode<T> *node);
	AVLNode<T>* rotateLR(AVLNode<T> *node);
	AVLNode<T>* rotateRL(AVLNode<T> *node);

public:
	AVLTree();

	void insertElement(T dat);
	void inOrder();
	void displayTree();
};

template <class T> AVLTree<T>::AVLTree()
{
	root = NULL;
	size = 0;
}

template <class T> void AVLTree<T>::insertElement(T dat)
{
	root = insertElementHelper(dat, root);
	size += 1;
}

template <class T> void AVLTree<T>::displayTree()
{
	display(root, 0);
}

template <class T> void AVLTree<T>::inOrder()
{
	inOrderHelper(root);
}

template <class T> AVLNode<T>* AVLTree<T>::insertElementHelper(T dat, AVLNode<T> *node)
{
	if(node == NULL)
	{
		AVLNode<T> *newNode = new AVLNode<T>(dat);
		return newNode;
	}

	if(dat <= node->data)
	{
		node->leftChild = insertElementHelper(dat, node->leftChild);
		node->heightLeft = std::max(node->leftChild->heightLeft, node->leftChild->heightRight) + 1;
	}
	else
	{
		node->rightChild = insertElementHelper(dat, node->rightChild);
		node->heightRight = std::max(node->rightChild->heightLeft, node->rightChild->heightRight) + 1;
	}

	if(abs(node->heightLeft - node->heightRight) > 1)
		node = adjustHeight(node, dat);

	return node;
}

template <class T> AVLNode<T>* AVLTree<T>::adjustHeight(AVLNode<T> *node, T dat)
{
	if(node->heightLeft > node->heightRight)
	{
		if(dat < node->leftChild->data)
			node = rotateLL(node);
		else
			node = rotateRL(node);
	}
	else
	{
		if(dat > node->rightChild->data)
			node = rotateRR(node);
		else
			node = rotateLR(node);
	}
	
	return node;
}

template <class T> void AVLTree<T>::padding(char c, int n)
{
	for(int i = 0; i < n; i++)
		std::cout<<c;
}

template <class T> void AVLTree<T>::display(AVLNode<T> *node, int level)
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
	display(node->leftChild, level+1);
}

template <class T> void AVLTree<T>::inOrderHelper(AVLNode<T> *node)
{
	if(node == NULL)
		return;

	inOrderHelper(node->leftChild);
	std::cout<<"<"<<node->heightLeft<<"> "<<node->data<<" <"<<node->heightRight<<">, ";
	inOrderHelper(node->rightChild);
}

template <class T> AVLNode<T>* AVLTree<T>::rotateLL(AVLNode<T> *node)
{
	AVLNode<T> *nextNode = node->leftChild;

	if(nextNode->rightChild != NULL)
	{
		node->leftChild = nextNode->rightChild;
		node->heightLeft = std::max(node->leftChild->heightLeft, node->leftChild->heightRight) + 1;
	}
	else
	{
		node->leftChild = NULL;
		node->heightLeft = 0;
	}

	nextNode->rightChild = node;
	nextNode->heightRight = std::max(node->heightLeft, node->heightRight) + 1;

	return nextNode;
}

template <class T> AVLNode<T>* AVLTree<T>::rotateRR(AVLNode<T> *node)
{
	AVLNode<T> *nextNode = node->rightChild;

	if(nextNode->leftChild != NULL)
	{
		node->rightChild = nextNode->leftChild;
		node->heightRight = std::max(node->rightChild->heightLeft, node->rightChild->heightRight) + 1;
	}
	else
	{
		node->rightChild = NULL;
		node->heightRight = 0;
	}

	nextNode->leftChild = node;
	nextNode->heightLeft = std::max(node->heightLeft, node->heightRight) + 1;

	return nextNode;
}

template <class T> AVLNode<T>* AVLTree<T>::rotateRL(AVLNode<T> *node)
{
	AVLNode<T> *nextNode = node->leftChild->rightChild;
	AVLNode<T> *tempNode = node->leftChild;

	if(nextNode->leftChild != NULL)
	{
		tempNode->rightChild = nextNode->leftChild;
		tempNode->heightRight = std::max(tempNode->rightChild->heightLeft, tempNode->rightChild->heightRight) + 1;
	}
	else
	{
		tempNode->rightChild = NULL;
		tempNode->heightRight = 0;
	}

	nextNode->leftChild = tempNode;
	nextNode->heightLeft = std::max(tempNode->heightLeft, tempNode->heightRight) + 1;

	if(nextNode->rightChild != NULL)
	{
		node->leftChild = nextNode->rightChild;
		node->heightLeft = std::max(node->leftChild->heightLeft, node->leftChild->heightRight) + 1;
	}
	else
	{
		node->leftChild = NULL;
		node->heightLeft = 0;
	}

	nextNode->rightChild = node;
	nextNode->heightRight = std::max(node->heightLeft, node->heightRight) + 1;

	return nextNode;
}

template <class T> AVLNode<T>* AVLTree<T>::rotateLR(AVLNode<T> *node)
{
	AVLNode<T> *nextNode = node->rightChild->leftChild;
	AVLNode<T> *tempNode = node->rightChild;

	if(nextNode->rightChild != NULL)
	{
		tempNode->leftChild = nextNode->rightChild;
		tempNode->heightLeft = std::max(tempNode->leftChild->heightLeft, tempNode->leftChild->heightRight) + 1;
	}
	else
	{
		tempNode->leftChild = NULL;
		tempNode->heightLeft = 0;
	}

	nextNode->rightChild = tempNode;
	nextNode->heightRight = std::max(tempNode->heightLeft, tempNode->heightRight) + 1;

	if(nextNode->leftChild != NULL)
	{
		node->rightChild = nextNode->leftChild;
		node->heightRight = std::max(node->rightChild->heightLeft, node->rightChild->heightRight) + 1;
	}
	else
	{
		node->rightChild = NULL;
		node->heightRight = 0;
	}

	nextNode->leftChild = node;
	nextNode->heightLeft = std::max(node->heightLeft, node->heightRight) + 1;

	return nextNode;
}
