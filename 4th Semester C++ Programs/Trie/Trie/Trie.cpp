#include <iostream>
#include <string>
using namespace std;
class Trie
{
private:
	class Bucket
	{
	public:
		string *keys;
		int noOfKeys, count;

		Bucket(int n)
		{
			noOfKeys = n;
			keys = new string[n];
			count = 0;
		}

		bool searchBucket(string data)
		{
			for(int i = 0; i < count; i++)
			{
				if(keys[i] == data)
					return true;
			}

			return false;
		}
	};

	class TrieNode
	{
	public:
		Bucket *b_arr[26];
		TrieNode *t_arr[26];
		string key;

		TrieNode()
		{
			for(int i = 0; i < 25; i++)
			{
				t_arr[i] = NULL;
				b_arr[i] = NULL;
			}

			key.clear();
		}
	};

	TrieNode *root;
	int height, bucketSize;

	
	TrieNode* removeHelper(TrieNode* tr,string data,int level);

public:
	Trie(int h, int bSize);

	void insert(string data);
	void search(string data);
	void remove(string data);
};

Trie::Trie(int h, int bSize)
{
	root = NULL;
	height = h;
	bucketSize = bSize;
}

void Trie::insert(string data)
{
	int pos;
	TrieNode *currentNode = root;
	int length = data.length();

	if(root == NULL)
	{
		root = new TrieNode();
		currentNode = root;
	}
	
	for( pos = 0; pos < length && pos < height-1 ; pos++)
	{
		if(currentNode->t_arr[data.at(pos) - 97] == NULL)
		{
			currentNode->t_arr[data.at(pos) - 97] = new TrieNode();
		}
		
		currentNode = currentNode->t_arr[data.at(pos) - 97];
	}

	if( pos == height-1 && pos < length )
	{
		if(currentNode->b_arr[pos] == NULL)
			currentNode->b_arr[pos] = new Bucket (bucketSize);

		currentNode->b_arr[pos]->keys[(currentNode->b_arr[pos]->count)++] = data;
	}
	else
	{
		currentNode->key = data;
	}
}

void Trie::search(string data)
{
	int pos;
	TrieNode *currentNode = root;
	int length = data.length();

	if(root == NULL)
	{
		cout<<"Not found...";
		return;
	}
	
	for( pos = 0; pos < length && pos < height-1 ; pos++)
	{
		if(currentNode->t_arr[data.at(pos) - 97] == NULL)
		{
			cout<<"Not found...";
			return;
		}
		
		currentNode = currentNode->t_arr[data.at(pos) - 97];
	}

	if( pos == height-1 && pos < length )
	{
		if(currentNode->b_arr[pos] == NULL)
		{
			cout<<"Not found...";
			return;
		}

		if(currentNode->b_arr[pos]->searchBucket(data) == true)
		{
			cout<<"Data present...";
			return;
		}
		else
		{
			cout<<"Not found...";
			return;
		}
	}
	else
	{
		if(currentNode->key == data)
		{
			cout<<"Data present...";
			return;
		}
		else
		{
			cout<<"Not found...";
			return;
		}
	}
}

TrieNode* Trie::removeHelper(TrieNode* tr,string data,int level)
{
}

void Trie::remove(string data)
{
	
	removeHelper(root,data);
}

int main()
{
	Trie tr(3, 5);
	tr.insert("abc");
	tr.insert("abcde");

	tr.search("abc");
	tr.search("bc");
	tr.search("abcde");
	
	return 0;
}