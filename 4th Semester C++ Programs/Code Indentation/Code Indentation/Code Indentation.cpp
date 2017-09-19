// Code Indentation.cpp : Defines the entry point for the console application.
//

#include <fstream>
#include "stacklnk.h"
using namespace std;

int main()
{
	char outputFileName[80], inputFileName[80], c;

	cout<<"Enter input filename: ";
	cin>>inputFileName;

	ifstream inFile(inputFileName, ios::in | ios::binary);
	if(!inFile)
	{
		cout<<"Error: Cannot open file...";
		system("pause");
		return 1;
	}

	cout<<"Enter output filename: ";
	cin>>outputFileName;

	ofstream outFile(outputFileName);
	if(!outFile)
	{
		cout<<"Error: Cannot open file...";
		system("pause");
		return 1;
	}

	Stack<char> braceStack;
	bool flag;
	bool forflag;
	
	while(inFile.get(c))
	{
		switch(c)
		{
		case '{':
			flag = false;
			outFile<<c<<endl;
			braceStack.push(c);
			for(int i = 1; i <= braceStack.getSize(); i++)
				outFile<<'\t';

			break;

		case '}':
			flag = false;
			braceStack.pop();
			outFile<<'\n';
			for(int i = 1; i <= braceStack.getSize(); i++)
				outFile<<'\t';

			outFile<<c<<endl;
			for(int i = 1; i <= braceStack.getSize(); i++)
				outFile<<'\t';

			break;

		case '(':
			flag = false;
			outFile<<c;
			forflag = true;
			break;

		case ')':
			flag = false;
			outFile<<c;
			forflag = false;
			break;

		case ';':
			if(forflag != true)
			{
				outFile<<c<<endl;
				for(int i = 1; i <= braceStack.getSize(); i++)
				outFile<<'\t';
				flag = true;
			}

		case '\n':
			if(flag)
				continue;

			outFile<<c;
			for(int i = 1; i <= braceStack.getSize(); i++)
				outFile<<'\t';

			break;

		case '\t':
			continue;

		default:
			flag = false;
			outFile<<c;
		}
	}

	outFile.close();
	inFile.close();

	cout<<endl<<"File indented successfully...";
	
	return 0;
}

