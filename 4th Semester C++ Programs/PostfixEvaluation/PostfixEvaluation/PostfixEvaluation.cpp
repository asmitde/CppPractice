// PostfixEvaluation.cpp : Defines the entry point for the console application.
//

#include "stacklnk.h"
#include <iostream>
using namespace std;

int main()
{
	char c, postfix[20];
	int i = 0, p = 0, nov = 0;
	float val, a, b, result;
	Stack<float> operandStack;

    cout<<"Enter postfix expression: ";
	cin>>postfix;

    while((c = postfix[i++]) != '\0')
    {
		try
		{
			switch(c)
			{
				case '^':
					b = operandStack.pop();
					a = operandStack.pop();
					result = pow(a, b);
					operandStack.push(result);
					break;
	
				case '/':
					b = operandStack.pop(); 
					a = operandStack.pop();
					result = a / b;
					operandStack.push(result);
					break;
	
				case '*':
					b = operandStack.pop();
					a = operandStack.pop();
					result = a * b;
					operandStack.push(result);
					break;
	
				case '+':
					b = operandStack.pop();
					a = operandStack.pop();
					result = a + b;
					operandStack.push(result);
					break;
	
				case '-':
					b = operandStack.pop();
					a = operandStack.pop();
					result = a - b;
					operandStack.push(result);
					break;
	
				default:
					cout<<endl<<"Enter the value of "<<c<<": ";
					cin>>val;
					operandStack.push(val);
			}
		}
		catch(StackException ex)
		{
			cout<<endl<<ex.error<<endl;
		}
	}
	 
	cout<<"\n\nResult = "<<result<<endl;
	return 0;
}

