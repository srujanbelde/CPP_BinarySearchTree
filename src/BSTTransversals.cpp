/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};
void rinorder(struct node *root, int *arr, int *k);
void rpreorder(struct node *root, int *arr, int *k);
void rpostorder(struct node *root, int *arr, int *k);
void inorder(struct node *root, int *arr)
{
	int k = 0;
	rinorder(root, arr, &k);
}
void rinorder(struct node *root, int *arr, int *k){
	if (arr != NULL)
	{
		if (root != NULL)
		{
			rinorder(root->left, arr, k);
			arr[(*k)++] = root->data;
			rinorder(root->right, arr, k);
		}
	}
}
void preorder(struct node *root, int *arr){
	int k = 0;
	rpreorder(root, arr, &k);
}
void rpreorder(struct node *root, int *arr, int *k){
	if (arr != NULL)
	{
		if (root != NULL)
		{
			arr[(*k)++] = root->data;
			rpreorder(root->left, arr, k);
			rpreorder(root->right, arr, k);

		}
	}
}
void postorder(struct node *root, int *arr){
	int k = 0;
	rpostorder(root, arr, &k);
}
void rpostorder(struct node *root, int *arr, int *k){
	if (arr != NULL)
	{
		if (root != NULL)
		{
			rpostorder(root->left, arr, k);
			rpostorder(root->right, arr, k);
			arr[(*k)++] = root->data;
		}
	}
}
