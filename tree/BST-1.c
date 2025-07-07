/*Binary Search Tree-Implemntation in C*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* GetNewNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

struct Node* Insert(struct Node* root, int data)
{
	if (root == NULL)//empty tree
	{
		root = GetNewNode(data);
	}
	else if (data <= root->data)
	{
		root->left = Insert(root->left, data);
	}
	else
	{
		root->right = Insert(root->right, data);
	}
	return root;
}

bool Search(struct Node* root, int data)
{
	if (root == NULL)
	{
		return false;
	}
	else if (root->data == data)
	{
		return true;
	}
	else if (data <= root->data)
	{
		return Search(root->left, data);
	}
	else
	{
		return Search(root->right, data);
	}
}

int main()
{
	struct Node* root = NULL;
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);
	int number;
	printf("Enter a number to search in BST:");
	scanf("%d", &number);
	if (Search(root, number))
	{
		printf("Number %d found in BST.\n", number);
	}
	else
	{
		printf("Number %d not found in BST.\n", number);
	}
	return 0;
}