/*PROG - Program to convert infix to postfix*/
/*Author: Asmit De   Date: 15.09.2011*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 20

float stack[MAX]; int top =- 1;

void push(float x)
{
    if(top == MAX-1) { printf("\nError: Stack overflow..."); getch(); exit(1); }
    stack[++top] = x;
    return;
}

float pop()
{
    if(top < 0) { printf("\nError: Stack underflow..."); exit(1); }
    return stack[top--];
}

int main()
{
    char c, postfix[20]; int i = 0, p = 0, nov = 0; float val, a, b, result;

    printf("Enter postfix expression: "); gets(postfix);

    while((c = postfix[i++]) != '\0')
    {
		switch(c)
		{
			case '^':
				b = pop(); a = pop();
				result = pow(a, b);
				push(result);
				break;

			case '/':
				b = pop(); a = pop();
				result = a / b;
				push(result);
				break;

			case '*':
				b = pop(); a = pop();
				result = a * b;
				push(result);
				break;

			case '+':
				b = pop(); a = pop();
				result = a + b;
				push(result);
				break;

			case '-':
				b = pop(); a = pop();
				result = a - b;
				push(result);
				break;

			default:
				printf("Enter the value of %c: ", c);
				scanf("%f", &val);
				push(val);
		}
    }
    
	printf("\n\nResult = %f\n", result);

	getch();
	return;
}