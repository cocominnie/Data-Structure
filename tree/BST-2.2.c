/*Find min and max element in a binary search tree*/
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

int FindMin(struct Node* root)
{
	if (root == NULL)
	{
		printf("Error: Tree is empty\n");
		return -1;
	}
	else if (root->left == NULL)
	{
		return root->data;
	}
	//Search in left subtree
	return FindMin(root->left);
}

int FindMax(struct Node* root)
{
	if (root == NULL)
	{
		printf("Error:Tree is empty\n");
		return -1;
	}
	else if (root->right == NULL)
	{
		return root->data;
	}
	//Search in right subtree
	return FindMax(root->right);
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
	number = FindMin(root);
	if (number != -1)
	{
		printf("The minimum number is %d\n", number);
	}
	number = FindMax(root);
	if (number != -1)
	{
		printf("The maximum number is %d\n", number);
	}
	return 0;
}