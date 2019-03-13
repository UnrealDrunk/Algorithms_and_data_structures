//Реализовать очередь.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void Push1(int i);
void Push2(int i);
int Pop1();
int Pop2();
void Enqueue();
void Dequeue();
void Display();
void Create();

int Stack_1[100], Stack_2[100];
int top1 = -1, top2 = -1;
int count = 0;

int main()
{
	int Choice;
	printf("Make your choice");
	printf("\n1 - Enqueue element into Queue");
	printf("\n2 - Dequeue element from Queue");
	printf("\n3 - Display the Queue");
	printf("\n4 - Exit program");
	Create();
	while (1)
	{
		printf("\nEnter choice ");
		scanf("%d", &Choice);
		switch (Choice)
		{
		case 1:
			Enqueue();
			break;
		case 2:
			Dequeue();
			break;
		case 3:
			Display();
			break;
		case 4:
			exit(0);
		default:
			printf("Wrong choice");
		}
	}
	getchar();
}


void Create()
{
	top1 = top2 = -1;
}


void Push1(int data)
{
	Stack_1[++top1] = data;
}

int Pop1()
{
	return(Stack_1[top1--]);
}

void Push2(int data)
{
	Stack_2[++top2] = data;
}


int Pop2()
{
	return(Stack_2[top2--]);
}


void Enqueue()
{
	int data;

	printf("Enter data into queue ");
	scanf("%d", &data);
	Push1(data);
	count++;
}


void Dequeue()
{
	int i;

	for (i = 0; i <= count; i++)
	{
		Push2(Pop1());
	}
	Pop2();
	count--;
	for (i = 0; i <= count; i++)
	{
		Push1(Pop2());
	}
	printf("\nItem is excluded from the queue\n");
}


void Display()
{
	printf("Displaying Queue: ");
	for (int i = 0; i <= top1; i++)
	{
		printf(" %d ", Stack_1[i]);
	}
	
}
