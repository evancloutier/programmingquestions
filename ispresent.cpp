#include <iostream>
#include <string>

class node {
    public:    
        int val;
        node *right, *left;
};

void insert(node **tree, node *item) {
    if(!(*tree)) {
            *tree = item;
            return;
    }
    if(item->val < (*tree)->val) {
            insert(&(*tree)->left, item);
    }
    else if(item->val > (*tree)->val) {
            insert(&(*tree)->right, item);
    }
}

// if found, return 1
// else, return 0

int isPresent (node *root, int val) {
	if (val == root->val)
		return 1;
	else if (val < root->val) {
		if (left == NULL)
			return 0;
		else
			return isPresent(root->left, val);
	}
	else if ( val > root->val) {
		if (right == NULL)
			return 0;
		else
			return isPresent(root->right, val);
	}
	return 0;
}