/*Doubly linked list-implemention in C*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
	struct Node* prev; //for doubly linked list 
};

struct Node* head;//global variable - pointer to head node

struct Node* GetNewNode(int x)
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = x;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}

void InsertAtHead(int x)
{
	struct Node* newnode = GetNewNode(x);
	if (head == NULL) //if list is empty
	{
		head = newnode;//head points to new node
		return;
	}
	head->prev = newnode;//new node points to old head
	newnode->next = head;
	head = newnode;//head points to new node
}

void InsertAtTail(int x)
{
	struct Node* newnode = GetNewNode(x);
	if (head == NULL) //if list is empty
	{
		head = newnode;//head points to new node
		return;
	}
	struct Node* temp = head;
	while (temp->next != NULL) //move to the last node
	{
		temp = temp->next;
	}
	temp->next = newnode;//last node points to new node
	newnode->prev = temp;//new node points to old last node
}

void Print()
{
	struct Node* temp = head;
	printf("Forward: ");
	while (temp != NULL) //print forward
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void ReversePrint()
{
	struct Node* temp = head;
	if (temp == NULL)
	{
		return;//empty list,exit
	}
	while (temp->next != NULL) //move to the last node
	{
		temp = temp->next;
	}
	printf("Reverse: ");
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->prev; //move to the previous pointer
	}
	printf("\n");
}

int main()
{
	head = NULL; //initialize head to NULL
	InsertAtHead(2); Print(); ReversePrint();
	InsertAtHead(4); Print(); ReversePrint();
	InsertAtHead(6); Print(); ReversePrint();
	head = NULL;//reset head to NULL for tail insertion
	InsertAtTail(2); Print(); ReversePrint();
	InsertAtTail(4); Print(); ReversePrint();
	InsertAtTail(6); Print(); ReversePrint();
	return 0;
}