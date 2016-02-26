/* Implement a function to check if a binary tree is a binary search
tree.
---> Leverage the definition: left.data <= current.data < right.data */

#include <iostream>
#include <climits>

struct Node {
	int data;
	Node *left, *right;
};

void createMinBST(Node* &root, int arr[], int start, int end) {
	if (start > end)
		return;
	if (root == NULL) {
		Node *ptr = new Node;
		int index = start + (end-start)/2;
		ptr->data = arr[index];
		ptr->left = NULL;
		ptr->right = NULL;
		root = ptr;
		createMinBST(root->left, arr, start, index-1);
		createMinBST(root->right, arr, index+1, end);
	}
}

bool checkBST(Node* root, int lower, int upper) {
	// Check if the current root is equal to NULL
	if (root == NULL)
		return true;
	// If we satisfy the definition of BST, recurse on children
	if (root->data <= upper && root->data >= lower)
		return (checkBST(root->left, lower, root->data) && checkBST(root->right, root->data+1, upper));
	else
		return false;
}