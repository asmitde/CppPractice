// InfixToPostfixConversion.cpp : Defines the entry point for the console application.
//

#include "stacklnk.h"
#include <iostream>
using namespace std;

int main()
{
	char c, infix[20], postfix[20];
	int i = 0, p = 0;
	Stack<char> operatorStack;

    cout<<"Enter infix expression: ";
	cin>>infix;

	try
	{
		while((c = infix[i++]) != '\0')
		{
			switch(c)
			{
				case '^':
				case '(':
					operatorStack.push(c);
					break;
	
				case ')':
					while(operatorStack.top() != '(')
						postfix[p++] = operatorStack.pop();
					operatorStack.pop();
					break; 
	
				case '/':
				case '*':
					while(!(operatorStack.getSize() == 0 || operatorStack.top() == '+' || operatorStack.top() == '-' || operatorStack.top() == '('))
						postfix[p++] = operatorStack.pop();
					operatorStack.push(c);
					break;
	
				case '+':
				case '-':
					while(!(operatorStack.getSize() == 0 || operatorStack.top() == '('))
						postfix[p++] = operatorStack.pop();
					operatorStack.push(c);
					break;
	
				default:
					postfix[p++] = c;
			}
		}
	 
		while(operatorStack.getSize() > 0)
			postfix[p++] = operatorStack.pop();
		postfix[p] = '\0';

		cout<<"\n\nPostfix expresssion: "<<postfix<<endl;
	}
	catch(StackException ex)
	{
		cout<<endl<<ex.error<<endl;
	}
	
	return 0;
}