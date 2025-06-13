#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* head;//global 

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
	while (temp != NULL && temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;//last node points to new node
}

void Print()//print all elements of the list
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

void Delete(int n)//delete node at position n
{
	struct Node* temp1 = head;
	if (n == 1)
	{
		head = temp1->next;//head points to second node
		free(temp1);//free the memory of first node
	}
	else
	{
		int i;
		for (i = 0; i < n - 2; i++)
		{
			temp1 = temp1->next;//temp1 points to (n-1)th node
		}
		struct Node* temp2 = temp1->next;//temp2 point to nth node
		temp1->next = temp2->next;//(n-1)th node points to (n+1)th node
		free(temp2);//free the memory of nth node
	}
}

int main()
{
	head = NULL;// empty list
	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5);//list :2,4,6,5
	Print();//print the original list
	int n;
	printf("Enter a positon to delete:");
	scanf("%d", &n);
	Delete(n);//delete node at position n
	Print();//print the list after deletion
}