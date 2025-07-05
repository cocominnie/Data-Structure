/*Queue - linked list implemention*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void Enqueue(int x)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = NULL;
	if (front == NULL && rear == NULL)
	{
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

void Dequeue()
{
	if (front == NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	struct Node* temp = front;
	if (front == rear)
	{
		front = rear = NULL;
	}
	else
	{
		front = front->next;
	}
	free(temp);
}

void IsEmpty()
{
	if (front == NULL)
	{
		printf("Queue is empty\n");
	}
	else
	{
		printf("Queue is not empty\n");
	}
}