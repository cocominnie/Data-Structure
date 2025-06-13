/*Building a new linked list in C program*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};


int main()
{
	struct Node* A;
	struct Node* temp1;
	A = NULL;
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = 2;
	temp->next = NULL;
	A = temp;// Assigning the address of temp to A
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = 4;
	temp->next = NULL;//Insert the new data to the end of the list
	temp1 = A;
	while (temp1->next != NULL)
	{
		temp1 = temp1->next;
	}//Traverse the list to find the last node
	temp1->next = temp;//Link the new node to the end of the list
}
