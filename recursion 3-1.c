/*Reversing the linked list using recursion without global variables in C program*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* head;

void Insert(int data)//insert an integer at end of list
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = data;
	newnode->next = NULL;
	struct Node* temp = head;
	if (temp == NULL)
	{
		head = newnode;//if list is empty,head points to new node
		return;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;//last node points to new node
}

void Reverse(struct Node* p)
{
	if (p->next == NULL)// move to the end of list
	{
		head = p;
		return;
	}
	Reverse(p->next);//
	struct Node* temp = p->next;// store the next node
	temp->next = p;//reverse the link
	p->next = NULL;// set the next of the current node to NULL
}

void PrintList(struct Node* head) // function to print the list
{
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

int main()
{
	head = NULL;// empty list
	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5);//list :2,4,6,5
	Reverse(head);// the reverse list 5,6,4,2
	PrintList(head); // print the reversed list
}