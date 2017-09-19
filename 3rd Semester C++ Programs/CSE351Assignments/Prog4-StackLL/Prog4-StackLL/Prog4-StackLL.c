#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

NODE *top = NULL, *temp;

int push(int num)
{
    temp = (NODE*)malloc(sizeof(NODE));
    if(temp == NULL)
		return 1;

    temp->data = num;
    temp->next = top;
    top = temp;
	return 0;
}

int pop()
{
    int value;
    if(top == NULL)
    {
		printf("\nEmpty Stack\n");
		return NULL; 
	}

    temp = top;
    value = temp->data;
    top = temp->next;
    free(temp);
    return value;
}

int main()
{
	char c;
	int data;

while(1)
{
	system("cls");
	puts("Choose an operation: ");
	puts("1\tDisplay contents of stack");
	puts("2\tPush data to stack");
	puts("3\tPop data from stack");
	puts("4\tExit");
	puts("\nEnter choice...");

	c = getch();
	fflush(stdin);

	switch(c)
	{
	case '1':
		system("cls");

		temp = top;
		printf("Stack contents:");
		while(temp != NULL)
		{
			printf("\n%d", temp->data);
			temp = temp->next;
		}

		printf("\n\nPress any key to return to menu...");
		getch();
		break;

	case '2':
		system("cls");

		printf("Enter the data to be pushed to stack: ");
		scanf("%d", &data);

		if(!push(data))
			printf("\nData pushed successfully...Press any key to return to menu...");
		else
			printf("\nError: Stack overflow...Press any key to return to menu...");
		getch();
		break;

	case '3':
		system("cls");

		printf("Popped value: %d \nPress any key to return to menu...", pop());
		getch();
		break;

	case '4':
		exit(0);

	default:
		system("cls");

		printf("Invalid input...Press any key to return to menu...");
		getch();
	}
}
}
