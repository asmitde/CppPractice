#include<iostream>
#include<stdlib.h>

using namespace std;

class closedHash
{
	int *hashTable;
	char *hashTag;
	int size;
	
	int hashFunction(int);
	
	public:
	closedHash(int n)
	{
		hashTable=new int[n];
		hashTag=new char[n];
		size=n;
		
		for(int i=0;i<n;i++)
			hashTag[i]='B';
	}
	
	//available functions
	void insert(int);
	int search(int);
	void remove(int);
};

int closedHash::hashFunction(int data)
{
	//modular hash function
	int key=data%size;
	
	return key;
}

void closedHash::insert(int data)
{
	int key=hashFunction(data);
	int offset=0;
	
	while(hashTag[key+offset]=='X' && hashTable[key+offset]!=data)
	{
		offset++;
		if(key+offset==size)
			offset=-key;
		if(offset==0)
		{
			cout<<"\nOVERFLOW\n";
			break;
		}
	}
	
	hashTable[key+offset]=data;
	hashTag[key+offset]='X';
}

int closedHash::search(int data)
{
	int key=hashFunction(data);
	int offset=0;
	
	while(hashTag[key+offset]=='D' || (hashTag[key+offset]=='X' && hashTable[key+offset]!=data))
	{
		offset++;
		if(key+offset==size)
			offset=-key;
		if(offset==0)
		{
			cout<<"\nNOT PRESENT\n";
			return -1;
		}
	}
	
	if(hashTag[key+offset]=='X' && hashTable[key+offset]==data)
		return key+offset;
	else
	{
		cout<<"\nNOT PRESENT\n";
		return -1;
	}
}

void closedHash::remove(int data)
{
	int key=search(data);
	
	if(key!=-1)
		hashTag[key]='D';
}

class openHash
{
	struct node
	{
		int data;
		node* link;
		
		node(int d)
		{
			data=d;
			link=NULL;
		}
	};
	
	node **hashTable;
	int size;

	int hashFunction(int);
	
	public:
	//constructor
	openHash(int n)
	{
		size=n;
		hashTable=new node*[n];
		for(int i=0;i<n;i++)
			hashTable[i]=NULL;
	}
	
	//function available
	void insert(int);
	void search(int);
	void remove(int);
};

int openHash::hashFunction(int data)
{
	int key=data%size;
	return key;
}

void openHash::insert(int data)
{
	int key=hashFunction(data);
	
	node *newNode=new node(data);
	
	newNode->link=hashTable[key];
	hashTable[key]=newNode;
}

void openHash::search(int data)
{
	int key=hashFunction(data);
	
	node *temp=hashTable[key];
	while(temp!=NULL)
	{
		if(temp->data==data)
		{
			cout<<"\nHASHED WITH KEY "<<key<<"\n";
			return;
		}
		temp=temp->link;
	}
	cout<<"\nNOT PRESENT\n";
}

void openHash::remove(int data)
{
	int key=hashFunction(data);
	
	node *temp=hashTable[key];
	node *prev=NULL;
	while(temp!=NULL)
	{
		if(temp->data==data)
		{
			if(prev==NULL)
			{
				hashTable[key]=temp->link;
				delete temp;
			}
			else
			{
				prev->link=temp->link;
				delete temp;
			}
			return;
		}
		temp=temp->link;
	}
	cout<<"\nNOT PRESENT\n";
}

int main(void)
{
	openHash h(5);
	
	h.insert(2);
	h.insert(10);
	h.insert(15);
	
	h.search(2);
	h.search(10);
	h.search(15);
	h.search(25);
	h.search(3);
	
	h.remove(2);
	h.remove(18);

	return 0;
}
