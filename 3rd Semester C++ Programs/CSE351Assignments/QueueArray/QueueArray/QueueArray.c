#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct Queue
{
	int _queue[SIZE];
	int front, rear;
}Queue;

void initQueue(Queue *q)
{
	q->front = -1;
	q->rear = -1;
}

int isFull(Queue *q)
{
	if(q->rear == SIZE - 1)
		return 1;
	else
		return 0;
}

int isEmpty(Queue *q)
{
	if(q->front == q->rear)
		return 1;
	else
		return 0;
}

int enqueue(Queue *q, int data)
{
	if(isFull(q))
	{
		printf("\n\aError: Queue is full...");
		return 1;
	}

	q->_queue[++q->rear] = data;
	return 0;
}

int dequeue(Queue *q, int *data)
{
	if(isEmpty(q))
	{
		printf("\n\aError: Queue is empty...");
		return 1;
	}

	*data = q->_queue[++q->front];
	return 0;
}

void displayQueue(Queue *q)
{
	int i;
	printf("Queue: ");
	for(i = q->rear; i >= q->front + 1; i--)
		printf("%d ", q->_queue[i]);
}

int main()
{
	Queue *queue = (Queue*)malloc(sizeof(Queue));
	int *data = (int*)malloc(sizeof(int));
	char choice;

	initQueue(queue);
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
			if(!enqueue(queue, *data))
				printf("\nData queued successfully...");

			printf("\n\nPress any key to return to menu...");
			getch();
			break;

		case '3':
			system("cls");

			if(!dequeue(queue, data))
				printf("\nData retrieved: %d", *data);

			printf("\n\nPress any key to return to menu...");
			getch();
			break;

		case '4':
			system("cls");

			initQueue(queue);
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