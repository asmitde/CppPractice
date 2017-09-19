
template <class T, int M> class BNode
{
public:
	int noOfKeys;
	T key[M - 1];
	BNode *link[M];

	BNode()
	{
		noOfKeys = 0;
		for(int i = 0; i < M - 1; i++)
		{
			key[i] = NULL;
			link[i] = NULL;
		}
		link[M - 1] = NULL;
	}

	BNode(T dat)
	{
		noOfKeys = 1;
		for(int i = 0; i < M - 1; i++)
		{
			key[i] = NULL;
			link[i] = NULL;
		}
		link[M - 1] = NULL;
		key[0] = dat;
	}
};

template <class T, int M> class BTree
{
private:
	BNode *root;
	int size;

	BNode<T, M>* insertElementHelper(T dat, BNode<T, M> *node);
	BNode<T, M>* case1(T dat, BNode<T, M> *node);
	BNode<T, M>* case2(T dat, BNode<T, M> *node);
	BNode<T, M>* case3(T dat, BNode<T, M> *node);

public:
	BTree();

	void insertElement(T dat);
};

template <class T, int M> BTree<T, M>::BTree()
{
	root = NULL;
	size = 0;
}

template <class T, int M> void BTree<T, M>::insertElement(T dat)
{
	insertElementHelper(dat, root);
	size++;
}

template <class T, int M> BNode<T, M>* BTree<T, M>::insertElementHelper(T dat, BNode<T, M> *node)
{
	if(root == NULL)
	{
		BNode<T, M> *newNode = new BNode<T, M>(dat);
		newNode->noOfKeys = 1;
		root = newNode;
		return NULL;
	}

	if(node->link[0] == NULL)
	{
		if(node->noOfKeys == M - 1)
		{
			if(node == root)
			{
				case2(dat, node);
				return NULL;
			}
			else
			{
				BNode<T, M> *tempNode = case3(dat, node);
				return tempNode;
			}
		}
		else
		{
			case1(dat, node);
			return NULL;
		}
	}
	else
	{
	}
}