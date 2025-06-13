/*Print elements of a linked list in forward using recursion in C program*/
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

void Print(struct Node* head)//print all elements of the list using recursion
{
	if (head == NULL)
	{
		return;
	}
	printf("%d ", head->data);//First print the data of current node
	Print(head->next);//Recursively call Print for next node
}

int main()
{
	struct Node* head = NULL;// empty list
	Insert(&head, 2);
	Insert(&head, 4);
	Insert(&head, 6);
	Insert(&head, 5);//list :2,4,6,5
	Print(head);//print the list
}