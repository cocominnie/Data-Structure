/*Delete a node from BST*/
#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

struct Node* FindMin(Node* root)
{
	if (root == NULL)
	{
		cout << "Tree is empty.";
		return NULL;
	}
	else if (root->left == NULL)
	{
		return root;
	}
	//Search in left subtree
	return FindMin(root->left);
}

struct Node* Delete(Node* root, int data)
{
	if (root == NULL)
	{
		return root;
	}
	else if (data < root->data)
	{
		root->left = Delete(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = Delete(root->right, data);
	}
	else // Get ready to be deleted
	{
		//Case 1:No child
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}
		//Case 2:One child
		else if (root->left == NULL)
		{
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL)
		{
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		//Case 3:2 children
		else
		{
			Node* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}
