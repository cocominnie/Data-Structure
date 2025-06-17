/*Array implementation of stack*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX 101

int A[MAX];
int top = -1;

void push(int x)
{
	if (top == MAX - 1)
	{
		printf("Stack overflow\n");
		return;
	}
	A[++top] = x; // Increment top and push x onto stack
}

void pop()
{
	if (top == -1)
	{
		printf("Stack underflow\n");
		return;
	}
	top--; // Decrement top to pop the top element
}

void print()
{
	int i;
	printf("Stack: ");
	for (i = 0; i <= top; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

int main()
{
	push(2); print();
	push(5); print();
	push(10); print();
	pop(); print();
	push(12); print();
	return 0;
}