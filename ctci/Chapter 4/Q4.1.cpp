/* Implement a function to check if a binary tree is balanced. 
For the purposes of this question, a balanced tree is defined to be a 
tree such that the heights of the two subtrees of any node never differ 
by more than one. */

#include <iostream>
#include <cmath>

struct Node {
	int data;
	Node *left, *right;
};

void insertNode(Node* &head, int data) {
	// If nothing exists in the tree yet
	if (head == NULL) {
		Node *p = new Node;
		p->data = data;
		p->left = NULL;
		p->right = NULL;
		head = p;
		return;
	}
	// If the data is less than the head data, we need to go left
	if (data <= head->data) {
		if (head->left == NULL) {
			Node *p = new Node;
			p->data = data;
			p->left = NULL;
			p->right = NULL;
			head->left = p;
			return;
		}
		// Keep calling until we get to the 'end' of the tree
		insertNode(head->left, data);
	}
	else {
		// If the data is greater, we go right
		if (head->right == NULL) {
			Node *p = new Node;
			p->data = data;
			p->left = NULL;
			p->right = NULL;
			head->right = p;
			return;
		}
		// Keep calling until we get to the 'end' of the tree
		insertNode(head->right, data);
	}
}

/* This runs in O(N log N) time since each node is "touched" once per
node above it. */

int height(Node* root) {
	if (root == NULL)
		return 0;
	return fmax(height(root->left), height(root->right)) + 1;
}

bool isBalanced(Node* root) {
	if (root == NULL)
		return true;
	int diff = height(root->left) - height(root->right);
	if (abs(diff) > 1)
		return false;
	else
		return (isBalanced(root->left) && isBalanced(root->right));
}

int main() {
	Node *root;
	root = NULL;
	int arr[] = {4, 7, 2, 1, 6, 8};

	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
		insertNode(root, arr[i]);
	std::cout << isBalanced(root) << std::endl;
}

/* We can also conduct this the following way - O(N) time and O(H) space
---> Where H is the height of the tree!
Use the above code first and then implement this afterward and explain
how it is a better solution */

int checkHeight(Node* root) {
	if (root == NULL)
		return 0; // i.e. height of 0

	// We can check if our left is balanced
	int leftHeight = checkHeight(root.left);
	if (leftHeight == -1)
		return -1;

	// We can check if our right is balanced
	int rightHeight = checkHeight(root.right);
	if (rightHeight = -1)
		return -1;

	// Finally we can check if the current node is balanced
	int heightDiff = leftHeight - rightHeight;
	if (abs(heightDiff) > 1)
		return -1;
	else
		return fmax(leftHeight, rightHeight) + 1;
}

bool isBalanced(Node* root) {
	if (checkHeight(root) == -1)
		return false;
	else
		return true;
}



