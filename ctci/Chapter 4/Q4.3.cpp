/* Given a sorted (increasing order) array with unique integer elements, 
write an algorithm to create a binary search tree with minimal height.
---> We want the root to be in the middle of the array! */

#include <iostream>

struct Node {
	int data;
	Node *left, *right;
};

void createBST(Node* &root, int arr[], int start, int end) {
	// Termination statement
	if (start > end)
		return;
	if (root == NULL) {
		Node *ptr = new Node;
		// Getting the index of the middle element
		int index = start + (end-start)/2;
		// Pushing the data into the tree
		ptr->data = arr[index];
		// Initializing our children to NULL
		ptr->left = NULL;
		ptr->right = NULL;
		// Setting the root to the current node to recursively call
		root = ptr;
		createBST(root->left, arr, start, index-1);
		createBST(root->right, arr, index+1, end);
	}
}

int main() {
	int myArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	Node* root;
	root = NULL;
	createBST(root, myArray, 0, 8);

	std::cout << root->left->data << " " << root->data << " " << root->right->data << std::endl;
}