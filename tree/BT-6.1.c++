/*Check if a binary tree is binary search tree*/
#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* GetNewNode(int data)
{
	Node* newNode = new Node;
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

bool IsSubtreeLesser(Node* root, int value)
{
	if (root == NULL)
	{
		return true;
	}
	if (root->data <= value
		&& IsSubtreeLesser(root->left, value)
		&& IsSubtreeLesser(root->right, value))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool IsSubtreeGreater(Node* root, int value)
{
	if (root == NULL)
	{
		return true;
	}
	if (root->data > value
		&& IsSubtreeGreater(root->left, value)
		&& IsSubtreeGreater(root->right, value))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool IsBinarySearchTree(Node* root)
{
	if (root == NULL)
	{
		return true;
	}
	if (IsSubtreeLesser(root->left, root->data)
		&& IsSubtreeGreater(root->right, root->data)
		&& IsBinarySearchTree(root->left)
		&& IsBinarySearchTree(root->right))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	Node* root = NULL;
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);
	bool number = IsBinarySearchTree(root);
	if (number == true)
	{
		cout << "It is a BST.";
	}
	else
	{
		cout << "It is not a BST.";
	}
	return 0;
}