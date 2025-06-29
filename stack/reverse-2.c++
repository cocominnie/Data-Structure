/*Reverse a string or linked list using stack*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<string.h>
#include<stdio.h>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

struct Node* head;

void Insert(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	Node* temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

void Reverse()
{
	if (head == NULL)
	{
		return;
	}
	stack<struct Node*> S;
	Node* temp = head;
	while (temp != NULL)
	{
		S.push(temp);
		temp = temp->next;
	}
	temp = S.top();
	head = temp;
	S.pop();
	while (!S.empty())
	{
		temp->next = S.top();
		S.pop();
		temp = temp->next;
	}
	temp->next = NULL;
}

void Print()
{
	Node* temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	head = NULL;
	Insert(2);
	Insert(5);
	Insert(8);
	Insert(3);
	Print();
	Reverse();
	Print();
}