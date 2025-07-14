/*Check if a binary tree is binary search tree(more efficient)*/
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

bool IsBstUtil(Node* root, int min, int max)
{
	// An empty tree is a BST
	if (root == NULL)
	{
		return true;
	}
	if (root->data > min && root->data < max
		&& IsBstUtil(root->left, min, root->data)
		&& IsBstUtil(root->right, root->data, max))
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
	return IsBstUtil(root, INT_MIN, INT_MAX);
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