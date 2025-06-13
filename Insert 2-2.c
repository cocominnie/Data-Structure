/*Inserting a new node at nth position without global variables in C program*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

void Insert(struct Node** head, int data, int n)
{
	struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
	temp1->data = data;
	temp1->next = NULL;
	if (n == 1)
	{
		temp1->next = *head;
		*head = temp1;
	}
	else
	{
		struct Node* temp2 = *head;
		for (int i = 0; i < n - 2; i++)
		{
			temp2 = temp2->next;
		}
		temp1->next = temp2->next;// link new node to next node
		temp2->next = temp1;// insert at position n
	}
}

void Print(struct Node* head)
{
	printf("Lise is :");
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

int main()
{
	struct Node* head = NULL;// empty list
	Insert(&head, 2, 1);
	Insert(&head, 3, 2);
	Insert(&head, 4, 1);
	Insert(&head, 5, 2);
	Print(head);
}
