/*PROG - Program to convert infix to postfix*/
/*Author: Asmit De   Date: 15.09.2011*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 20

char stack[MAX]; int top =- 1;

void push(char x)
{
    if(top == MAX-1) { printf("\nError: Stack overflow..."); getch(); exit(1); }
    stack[++top] = x;
    return;
}

char pop()
{
    if(top < 0) { printf("\nError: Stack underflow..."); exit(1); }
    return stack[top--];
}

int main()
{
    char c, infix[20], postfix[20]; int i = 0, p = 0;

    printf("Enter infix expression: "); gets(infix);

    while((c = infix[i++]) != '\0')
    {
		switch(c)
		{
			case '^':
			case '(':
				push(c);
				break;

			case ')':
				while(stack[top] != '(')
					postfix[p++] = pop();
				pop();
				break; 

			case '/':
			case '*':
				while(!(stack[top] == '+' || stack[top] == '-' || stack[top] == '(' || top < 0))
					postfix[p++] = pop();
				push(c);
				break;

			case '+':
			case '-':
				while(!(stack[top] == '(' || top < 0))
					postfix[p++] = pop();
				push(c);
				break;

			default:
				postfix[p++] = c;
		}
    }
    
	while(top >= 0)
		postfix[p++] = pop();
    postfix[p] = '\0';
    
	printf("\n\nPostfix expresssion: %s\n", postfix);

	getch();
	return;
}