	enum Color
	{
		RED,
		BLACK
	};

	enum ModCode
	{
		OK,
		RED_NODE,
		LEFT_RED,
		RIGHT_RED
	};

	template <class T> class RBNode
	{
	public:
		T data;
		RBNode *leftChild, *rightChild;
		Color linkColor;
		
		RBNode(const T &d, RBNode *lc = NULL, RBNode *rc = NULL, Color clr = RED)
		{
			data = d;
			leftChild = lc;
			rightChild = rc;
			linkColor = clr;
		}
	};

template <class T> class RBTree
{
private:
	RBNode<T> *root;
	int size;

	ModCode insertHelper(RBNode<T> *&currentNode, T data);

	ModCode modifyLeft(RBNode<T> *&currentNode, ModCode childStatus);
	ModCode modifyRight(RBNode<T> *&currentNode, ModCode childStatus);
	ModCode flipColor(RBNode<T> *currentNode);
	ModCode rotateLL(RBNode<T> *&currentNode);
	ModCode rotateRL(RBNode<T> *&currentNode);
	ModCode rotateRR(RBNode<T> *&currentNode);
	ModCode rotateLR(RBNode<T> *&currentNode);

	void display(RBNode<T> *node, int level);
	void padding(char c, int n);

public:

	RBTree();

	void insert(T data);
	void displayTree();
};

template <class T> RBTree<T>::RBTree()
{
	root = NULL;
	size = 0;
}

template <class T> void RBTree<T>::insert(T data)
{
	ModCode status = insertHelper(root, data);

	if(status == RED_NODE)
		root->linkColor = BLACK;

	size++;
}

template <class T> ModCode RBTree<T>::insertHelper(RBNode<T> *&currentNode, T data)
{
	ModCode status, childStatus;

	if(currentNode == NULL)
	{
		currentNode = new RBNode<T>(data);
		return RED_NODE;
	}

	if(data < currentNode->data)
	{
		childStatus = insertHelper(currentNode->leftChild, data);
		status = modifyLeft(currentNode, childStatus);
	}
	else
	{
		childStatus = insertHelper(currentNode->rightChild, data);
		status = modifyRight(currentNode, childStatus);
	}

	return status;
}

template <class T> ModCode RBTree<T>::modifyLeft(RBNode<T> *&currentNode, ModCode childStatus)
{
	ModCode status = OK;
	RBNode<T> *aunt = currentNode->rightChild;
	Color auntColor = BLACK;
	if(aunt != NULL)
		auntColor = aunt->linkColor;

	switch(childStatus)
	{
	case RED_NODE:
		if(currentNode->linkColor == RED)
			status = LEFT_RED;

		break;

	case LEFT_RED:
		if(auntColor == BLACK)
			status = rotateLL(currentNode);
		else
			status = flipColor(currentNode);

		break;

	case RIGHT_RED:
		if(auntColor == BLACK)
			status = rotateRL(currentNode);
		else
			status = flipColor(currentNode);

		break;

	default:
		break;
	}

	return status;
}

template <class T> ModCode RBTree<T>::modifyRight(RBNode<T> *&currentNode, ModCode childStatus)
{
	ModCode status = OK;
	RBNode<T> *aunt = currentNode->leftChild;
	Color auntColor = BLACK;
	if(aunt != NULL)
		auntColor = aunt->linkColor;

	switch(childStatus)
	{
	case RED_NODE:
		if(currentNode->linkColor == RED)
			status = RIGHT_RED;

		break;

	case LEFT_RED:
		if(auntColor == BLACK)
			status = rotateLR(currentNode);
		else
			status = flipColor(currentNode);

		break;

	case RIGHT_RED:
		if(auntColor == BLACK)
			status = rotateRR(currentNode);
		else
			status = flipColor(currentNode);

		break;

	default:
		break;
	}

	return status;
}

template <class T> ModCode RBTree<T>::rotateLL(RBNode<T> *&node)
{
	RBNode<T> *nextNode = node->leftChild;

	if(nextNode->rightChild != NULL)
		node->leftChild = nextNode->rightChild;
	else
		node->leftChild = NULL;

	nextNode->rightChild = node;
	node->linkColor = RED;
	nextNode->linkColor = BLACK;
	node = nextNode;
	
	return OK;
}

template <class T> ModCode RBTree<T>::rotateRR(RBNode<T> *&node)
{
	RBNode<T> *nextNode = node->rightChild;

	if(nextNode->leftChild != NULL)
		node->rightChild = nextNode->leftChild;
	else
		node->rightChild = NULL;

	nextNode->leftChild = node;
	node->linkColor = RED;
	nextNode->linkColor = BLACK;
	node = nextNode;

	return OK;
}

template <class T> ModCode RBTree<T>::rotateRL(RBNode<T> *&node)
{
	RBNode<T> *nextNode = node->leftChild->rightChild;
	RBNode<T> *tempNode = node->leftChild;

	if(nextNode->leftChild != NULL)
		tempNode->rightChild = nextNode->leftChild;
	else
		tempNode->rightChild = NULL;

	nextNode->leftChild = tempNode;

	if(nextNode->rightChild != NULL)
		node->leftChild = nextNode->rightChild;
	else
		node->leftChild = NULL;


	nextNode->rightChild = node;
	node->linkColor = RED;
	nextNode->linkColor= BLACK;
	node = nextNode;

	return OK;
}

template <class T> ModCode RBTree<T>::rotateLR(RBNode<T> *&node)
{
	RBNode<T> *nextNode = node->rightChild->leftChild;
	RBNode<T> *tempNode = node->rightChild;

	if(nextNode->rightChild != NULL)
		tempNode->leftChild = nextNode->rightChild;
	else
		tempNode->leftChild = NULL;

	nextNode->rightChild = tempNode;
	
	if(nextNode->leftChild != NULL)
		node->rightChild = nextNode->leftChild;
	else
		node->rightChild = NULL;

	nextNode->leftChild = node;
	node->linkColor = RED;
	nextNode->linkColor= BLACK;
	node = nextNode;

	return OK;
}

template <class T> ModCode RBTree<T>::flipColor(RBNode<T> *currentNode)
{
	currentNode->leftChild->linkColor = BLACK;
	currentNode->rightChild->linkColor = BLACK;
	currentNode->linkColor = RED;

	return RED_NODE;
}

template <class T> void RBTree<T>::padding(char c, int n)
{
	for(int i = 0; i < n; i++)
		std::cout<<c;
}

template <class T> void RBTree<T>::display(RBNode<T> *node, int level)
{
	if(node == NULL)
	{
		padding('\t', level);
		std::cout<<'~'<<std::endl;
		return;
	}

	display(node->rightChild, level+1);
	padding('\t', level);
	std::cout<<"("<<node->linkColor<<") "<<node->data<<endl;
	display(node->leftChild, level+1);
}

template <class T> void RBTree<T>::displayTree()
{
	display(root, 0);
}