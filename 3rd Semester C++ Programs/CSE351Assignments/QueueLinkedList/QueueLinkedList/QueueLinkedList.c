#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE *getNode(int data)
{
	NODE *node = (NODE*)malloc(sizeof(NODE));
	
	if(node == NULL)
		return NULL;

	node->data = data;
	node->next = NULL;
   return node;
}

NODE *enqueue(NODE *list, int data)
{
	NODE *node = getNode(data);
	if(node == NULL)
	{
		printf("\n\aError: Queue is full...");
		return NULL;
	}
	
	node->next = list;
	return node;
}

NODE *dequeue(NODE *list, int *data)
{
	NODE *temp = list;
	if(list->next == NULL)
	{
		*data = list->data;
		free(list);
		return NULL;
	}
	else
	{
		while(list->next->next != NULL)
			list = list->next;

		*data = list->next->data;
		free(list->next);
		list->next = NULL;
		return temp;
	}
}

void displayQueue(NODE *list)
{
	printf("\nQueue: ");
	while(list != NULL)
	{
		printf("%d ", list->data);
		list = list->next;
	} 
}

NODE *clearQueue(NODE *list)
{
	NODE *temp = NULL;
	while(list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
	return list;
}

int main()
{
	NODE *queue = NULL;
	int *data = (int*)malloc(sizeof(int));
	char choice;

	while(1)
	{
		system("cls");
		puts("MENU");
		puts("\nKey \tFunction");
		puts("1 \tDisplay Queue");
		puts("2 \tEnqueue Data");
		puts("3 \tDequeue Data");
		puts("4 \tClear Queue");
		puts("X \tExit");
		printf("\nEnter choice...");
		choice = getch();
		fflush(stdin);

		switch(choice)
		{
		case '1':
			system("cls");

			displayQueue(queue);

			printf("\n\nPress any key to return to menu...");
			getch();
			break;

		case '2':
			system("cls");

			printf("Enter data: ");
			scanf("%d", data);
			queue = enqueue(queue, *data);
			if(queue != NULL)
				printf("\nData queued successfully...");

			printf("\n\nPress any key to return to menu...");
			getch();
			break;

		case '3':
			system("cls");

			if(queue != NULL)
			{
				queue = dequeue(queue, data);
				printf("\nData retrieved: %d", *data);
			}
			else
				printf("\n\aError: Queue is empty...");

			printf("\n\nPress any key to return to menu...");
			getch();
			break;

		case '4':
			system("cls");

			queue = clearQueue(queue);
			printf("Queue cleared successfully...");

			printf("\n\nPress any key to return to menu...");
			getch();
			break;

		case 'X':
		case 'x':
			exit(0);

		default:
			system("cls");

			printf("\aError: Invalid Input...");

			printf("\n\nPress any key to return to menu...");
			getch();
		}
	}
}