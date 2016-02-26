/* Write an algorithm to find the 'next' node (i.e. in-order successor) 
of a given node in a binary search tree. You may assume that each node 
has a link to its parent. */

#include <iostream>
#include <stack>

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

Node* inOrderSuccessor(Node* root, int k) {
	std::stack<Node*> S;
	Node *ptr = root;
	bool searched = false;
	while (true) {
		// Getting to the leftmost node
		while (ptr) {
			S.push(ptr);
			ptr = ptr->left;
		}
		// We search until the stack is empty
		if (S.empty())
			break;
		ptr = S.top();
		S.pop();

		if (searched)
			return ptr;
		if (ptr->data == k)
			searched = true;
		ptr = ptr->right;
	}
	return false;
}
