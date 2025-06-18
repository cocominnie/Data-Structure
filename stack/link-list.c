/*Link list implementation of stack*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* link;
};

struct Node* top = NULL;

void Push(int x)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->link = top; //link the new node to the previous top
	top = temp; //make the new node the top of the stack
}

void Pop()
{
	struct Node* temp;
	if (top == NULL) //if stack is empty
	{
		return;
	}
	temp = top; //store the current top node
	top = top->link; //move the top pointer to the next node
	free(temp); //free the memory of the popped node
}

int Top()
{
	if (top == NULL) //if stack is empty
	{
		return -1; // or some other error value
	}
	return top->data; //return the data of the top node
}

int IsEmpty()
{
	return top == NULL; //return 1 if stack is empty, 0 otherwise
}

void Print()
{
	struct Node* temp = top; //start from the top of the stack
	while (temp != NULL) //traverse the stack
	{
		printf("%d ", temp->data); //print the data of each node
		temp = temp->link; //move to the next node
	}
	if (IsEmpty()) //check if stack is empty
	{
		printf("Stack is empty");
	}
	else
	{
		printf("Top element is %d", Top()); //print the top element
	}
	printf("\n");
}

int main()
{
	top = NULL; //initialize the stack to be empty
	Push(10); Print();
	Push(20); Print();
	Push(30); Print();
	Pop(); Print();
	Push(40); Print();
	Pop(); Print();
	Pop(); Print();
	Pop(); Print();
	return 0;
}