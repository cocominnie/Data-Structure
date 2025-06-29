/*Reverse a string or linked list using stack*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<string.h>
#include<stdio.h>
using namespace std;

void Reverse(char c[], int n)
{
	stack<char> S;
	//loop for push
	for (int i = 0; i < n; i++)
	{
		S.push(c[i]);
	}
	//loop for pop
	for (int i = 0; i < n; i++)
	{
		c[i] = S.top();
		S.pop();
	}
}

int main()
{
	char c[51];
	printf("Enter a string: ");
	gets_s(c);// using gets_s for safety
	Reverse(c, strlen(c));
	printf("Output = %s", c);
	return 0;
}