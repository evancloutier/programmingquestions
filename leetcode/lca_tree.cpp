#include <iostream>
#include <vector>

struct Node {
	int data;
	Node *left, *right;
};

Node findLCA(Node *root, Node *p, Node *q) {
	// Check if the root exists
	if (!root)
		return NULL;
	// If p or q is a direct child of the root then root is the LCA
	if (root == p || root == q)
		return root;
	// Get LCA of p and q in the left subtree
	Node *L = LCA(root->left, p, q);
	// Get LCA of p and q in the right subtree
	Node *R = LCA(root->right, p, q);
	// If p or q is in the left subtree and the other is in the right, then root is the LCA
	if (L && R)
		return root;
	// Otherwise, L is the LCA
	else if (L)
		return L;
	// Otherwise, R is the LCA
	else
		return R;
}