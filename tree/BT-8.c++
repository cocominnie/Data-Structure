/*Inorder Successor in a binary search tree*/
#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

//Function to find Node with minimum value in a BST
Node* FindMin(struct Node* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root;
}

//Function to ensure if there is a data in the tree
Node* Find(struct Node* root, int data)
{
	if (root == NULL)
	{
		return NULL;
	}
	else if (root->data == data)
	{
		return root;
	}
	else if (data <= root->data)
	{
		return Find(root->left, data);
	}
	else
	{
		return Find(root->right, data);
	}
}

//Function to find successor
Node* Getsuccessor(struct Node* root, int data)
{
	//Search the node-O(h)
	struct Node* current = Find(root, data);
	if (current == NULL)
	{
		return NULL;
	}
	//Case 1:Node has right subtree
	if (current->right != NULL)
	{
		return FindMin(current->right);//O(h)
	}
	//Case 2:No right subtree-O(h)
	else
	{
		Node* successor = NULL;
		Node* ancestor = root;
		while (ancestor != current)
		{
			if (current->data < ancestor->data)
			{
				successor = ancestor;// So far this is the deepest node for which current node is in left
				ancestor = ancestor->left;
			}
			else
			{
				ancestor = ancestor->right;
			}
		}
		return successor;
	}
}