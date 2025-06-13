/*Print elements of a linked list in forward and reverse order using recursion in C program*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

void Insert(struct Node** head, int data)//insert an integer at end of list
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = data;
	newnode->next = NULL;
	struct Node* temp = *head;
	if (temp == NULL)
	{
		*head = newnode;//if list is empty,head points to new node
		return;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;//last node points to new node
}

void Printreverse(struct Node* head)//print all elements of the list and reverse order using recursion
{
	if (head == NULL)
	{
		return;
	}
	Printreverse(head->next);//recursive call to print next node first
	printf("%d ", head->data);//print current node data after returning from recursive call
}

int main()
{
	struct Node* head = NULL;// empty list
	Insert(&head, 2);
	Insert(&head, 4);
	Insert(&head, 6);
	Insert(&head, 5);//list :2,4,6,5
	Printreverse(head);//print the list 5,6,4,2
}