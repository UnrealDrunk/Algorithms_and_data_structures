//Создать функцию, копирующую односвязный список (то есть создает в памяти копию односвязного списка, без удаления первого списка).

#include <stdio.h>
#include <stdlib.h>


struct Node
{
	char data;
	struct Node* next;
};


void PrintList(struct Node* head)
{
	struct Node* ptr = head;
	while (ptr)
	{
		printf("%c ", ptr->data);
		ptr = ptr->next;
	}

}


void Push(struct Node** head, int data)
{
	
	struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
	NewNode->data = data;

	NewNode->next = *head;

	*head = NewNode;
}


struct Node* CopyList(struct Node* head)
{
	struct Node* CurrentList = head;	 
	struct Node* NewList = NULL; 
	struct Node* Tail = NULL;	 

	while (CurrentList != NULL)
	{
		
		if (NewList == NULL)
		{
			Push(&NewList, CurrentList->data);
			Tail = NewList;
		}
		else
		{
			Push(&(Tail->next), CurrentList->data);
			Tail = Tail->next;		 
		}
		CurrentList = CurrentList->next;
	}

	return NewList;
}


int main(void)
{
	
	char InitialData[] = "Geekbrains";
	int DataSize = sizeof(InitialData) / sizeof(InitialData[0]);

	
	struct Node* CurrentList = NULL;

	for (int i = DataSize - 1; i >= 0; i--)
		Push(&CurrentList, InitialData[i]);

	printf("We've constructed new linked list, Current linked list:\n");
	PrintList(CurrentList);

	printf("\n\nAfter that we've copied Current List to Duplicated List:\n");
	
	struct Node* DuplicatedList = CopyList(CurrentList);

	PrintList(DuplicatedList);

	printf("\n\nAnd the Current list was not broken or delited, let's print it again:\n");
	PrintList(CurrentList);

	getchar();
	
}
