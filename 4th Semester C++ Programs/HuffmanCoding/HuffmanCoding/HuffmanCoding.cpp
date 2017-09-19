// HuffmanCoding.cpp : Defines the entry point for the console application.
//

#include <string>
#include "queuelnk.h"
using namespace std;

struct HTNode
{
	char symbol;
	HTNode *leftChild, *rightChild;

	HTNode(char s, HTNode *lc = NULL, HTNode *rc = NULL)
	{
		symbol = s;
		leftChild = lc;
		rightChild = rc;
	}
};

int frequencyMap[256];
string huffCodes[256];

void ComputeFrequency(string &str)
{
	for(int i = 0; i < 256; i++)
		frequencyMap[i] = 0;

	char c;
	for(int i = 0; i < str.length(); i++)
	{
		c = str.at(i);
		frequencyMap[c]++;
	}
}



void HuffmanMap(HTNode *HT, string &code)
{
	if(HT->leftChild == NULL && HT->rightChild == NULL)
	{
		huffCodes[HT->symbol] = code;
		return;
	}

	HuffmanMap(HT->leftChild, code.append("0"));
	code = code.erase(code.length() - 1);
	HuffmanMap(HT->rightChild, code.append("1"));
	code = code.erase(code.length() - 1);
}

void GenerateHuffmanString(HTNode *HT, string &str, string &hCode)
{
	for(int i = 0; i < str.length(); i++)
	{
		char s = str.at(i);
		string code;
		bool flag = false;
		code = huffCodes[s];
		cout<<"code for "<<s<<" is "<<code<<endl;
		hCode.append(code);
	}
}	

string GenerateHuffmanCode(string &str)
{
	string hCode;
	ComputeFrequency(str);

	PriorityQueue<HTNode*> HQ;

	for(int i = 0; i < 256; i++)
	{
		if(frequencyMap[i] != 0)
		{
			HTNode *tree = new HTNode(i);
			HQ.enqueue(tree, frequencyMap[i]);
		}
	}

	while(HQ.getSize() > 1)
	{
		float f1 = HQ.getFrontKey();
		HTNode *l = HQ.dequeue();
		float f2 = HQ.getFrontKey();
		HTNode *r = HQ.dequeue();

		HTNode *HT = new HTNode('`', l, r);
		HQ.enqueue(HT, f1 + f2);
	}

	HTNode *HT = HQ.dequeue();

	for(int i = 0; i < 256; i++)
		huffCodes[i] = "";

	string e = "";
	HuffmanMap(HT, e);
	GenerateHuffmanString(HT, str, hCode);

	return hCode;
}


int main()
{
	cout<<"Enter a string: ";
	string str;
	getline(cin, str);

	string hc = GenerateHuffmanCode(str);
	cout<<endl<<"Huffman code:\n"<<hc<<endl;
	
	return 0;
}

