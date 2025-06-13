/*Reverse a linked list without global variables in C program*/
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
	while (temp != NULL && temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;//last node points to new node
}

void Print(struct Node* head)//print all elements of the list
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

void Reverse(struct Node** head)//reverse the linked list
{
	struct Node* prev = NULL;
	struct Node* current = *head;
	struct Node* next = NULL;
	while (current != NULL)
	{
		next = current->next;//Store next node
		current->next = prev;//Reverse the link
		prev = current;      //Move prev to current node
		current = next;      //Move to next node
	}
	*head = prev;//Updata head to point to the new first node
}

int main()
{
	struct Node* head = NULL;// empty list
	Insert(&head, 2);
	Insert(&head, 4);
	Insert(&head, 6);
	Insert(&head, 5);//list :2,4,6,5
	Print(head);//print the original list
	Reverse(&head);//reverse the list
	Print(head);//print the list after deletion
}