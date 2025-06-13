/*Inserting a new node with global variables in C program*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* head;//global variable to hold the head of the linked list

void Insert(int x)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = head;
	head = temp;//Insert at the beginning of the list
}

void Print()
{
	struct Node* temp = head;
	printf("Lise is :");
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	head = NULL;//empty list
	printf("Enter the number of nodes:");
	int n, i, x;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Enter data for node %d:", i + 1);
		scanf("%d", &x);
		Insert(x);
		Print();
	}
}
