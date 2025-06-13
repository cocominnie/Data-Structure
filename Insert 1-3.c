/*Another way to insert a new node without global variables in C program*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

void Insert(struct Node** head, int x)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = *head;
	*head = temp;//Insert at the beginning of the list
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
	struct Node* head = NULL;//empty list
	printf("Enter the number of nodes:");
	int n, i, x;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Enter data for node %d:", i + 1);
		scanf("%d", &x);
		Insert(&head, x);
		Print(head);
	}
}
